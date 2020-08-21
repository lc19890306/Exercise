#pragma once

#include <mutex>
#include <queue>

using namespace std;

template <typename T>
class thread_safe_queue {
public:
    thread_safe_queue() = default;
    thread_safe_queue(const thread_safe_queue &other) {
        lock_guard<mutex> lk(other.mtx);
        q = other.q;
    }
    thread_safe_queue(thread_safe_queue &&other) {
        lock_guard<mutex> lk(other.mtx);
        q = move(other.q);
    }
    thread_safe_queue &operator=(thread_safe_queue rhs) {
        scoped_lock<mutex> lk(mtx, rhs.mtx);
        swap(q, rhs.q);
    }
    void push(T x) { // rvalue调用move ctor不用copy
        lock_guard<mutex> lk(mtx); // 比unique_lock简单且性能好
        q.push(move(x)); // rvalue不用copy
        cond.notify_one(); // 一定要通知挂起等待的线程
    }
    T pop() {
        // shared_lock<shared_mutex> lk(mtx);
        unique_lock<mutex> lk(mtx); // 条件变量必须配合unique_lock使用，因为unique_lock有lock和unlock函数
        cond.wait(lk, [this]{ return !q.empty(); }); // 当predicate不满足的时候cond释放锁并挂起线程等待，只有当被notify且predicate满足时才重新获得锁继续执行
        const T res = move(q.front());
        q.pop();
        return res;
    }
    bool try_pop(T &value) {
        lock_guard<mutex> lk(mtx);
        if (q.empty()) return false;
        value = q.front();
        q.pop();
        return true;
    }
    bool empty() const {
        lock_guard<mutex> lk(mtx);
        return q.empty();
    }

private:
    mutable mutex mtx;
    // mutable shared_mutex mtx; // 这里不适合用读写锁因为push和pop都要修改queue
    queue<T> q;
    condition_variable cond;
    // condition_variable_any cond;
};
