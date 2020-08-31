#pragma once

#include <memory>
#include <mutex>

template<typename T, int NumOfObjects = 20>
class MemPool {
public:
    ~MemPool() {
        auto p = memBlockHeader;
        while (p) {
            auto t = p->pNext;
            delete p;
            p = t;
        }
    }

    template<typename ...Args>
    auto alloc(Args &&...args);

private:
    void free(T *);

    //空闲节点结构体
    struct FreeNode {
        char data[sizeof(T)];
        FreeNode *pNext{};
    };

    //内存块结构体
    struct MemBlock {
        FreeNode data[NumOfObjects];
        MemBlock *pNext{};
    };

    FreeNode *freeNodeHeader{};
    MemBlock *memBlockHeader{};
    mutex mtx;
};

//分配空闲的节点
template<typename T, int NumOfObjects>
template<typename ...Args>
auto MemPool<T, NumOfObjects>::alloc(Args &&...args) {
    lock_guard<mutex> lk(mtx);
    //无空闲节点，申请新内存块
    if (!freeNodeHeader) {
        auto newBlock = new MemBlock;
        newBlock->pNext = nullptr;

        freeNodeHeader = &newBlock->data[0];     //设置内存块的第一个节点为空闲节点链表的首节点
        //将内存块的其它节点串起来
        for (int i = 1; i < NumOfObjects; ++i) {
            newBlock->data[i - 1].pNext = &newBlock->data[i];
        }
        newBlock->data[NumOfObjects - 1].pNext = nullptr;

        //首次申请内存块
        if (!memBlockHeader) {
            memBlockHeader = newBlock;
        } else {
            //将新内存块加入到内存块链表
            newBlock->pNext = memBlockHeader;
            memBlockHeader = newBlock;
        }
    }
    //返回空节点闲链表的第一个节点
    auto freeNode = freeNodeHeader;
    freeNodeHeader = freeNodeHeader->pNext;
    return unique_ptr<T, std::function<void(T *)>>(new(freeNode)T(forward<Args>(args)...), [this](T *p) { free(p); });
}

//释放已经分配的节点
template<typename T, int NumOfObjects>
void MemPool<T, NumOfObjects>::free(T *p) {
    lock_guard<mutex> lk(mtx);
    p->~T();
    auto pNode = reinterpret_cast<FreeNode *>(p);
    pNode->pNext = freeNodeHeader;    //将释放的节点插入空闲节点头部
    freeNodeHeader = pNode;
}
