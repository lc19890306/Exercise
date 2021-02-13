#include <iostream>
#include <mutex>

using namespace std;

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

    T *alloc();

    void free(T *);

private:
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
T *MemPool<T, NumOfObjects>::alloc() {
    lock_guard<mutex> lk(mtx);
    //无空闲节点，申请新内存块
    if (!freeNodeHeader) {
        auto newBlock = new MemBlock;

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
    return new(freeNode)T();
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

class ActualClass {
    static int count;
    int No;

public:
    ActualClass() {
        No = ++count;
    }

    void print() {
        cout << this << ": ";
        cout << "the " << No << "th object" << endl;
    }
};

int ActualClass::count = 0;

int main() {
    //定义内存池对象
    MemPool<ActualClass, 2> mp;

    auto p1 = mp.alloc();
    p1->print();

    auto p2 = mp.alloc();
    p2->print();
    mp.free(p1);

    p1 = mp.alloc();
    p1->print();

    auto p3 = mp.alloc();
    p3->print();

    mp.free(p1);
    mp.free(p2);
    mp.free(p3);
}
