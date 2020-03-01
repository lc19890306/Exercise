include <mutex>
#include <queue>

using namespace std;

template <typename T>
class thread_safe_queue {
public:
    void push(const T &x) {
        lock_guard<mutex> lk(mtx); // 比unique_lock简单且性能好
        q.push(x);
        cond.notify_one(); // 一定要通知挂起等待的线程
    }
    T pop() {
        unique_lock<mutex> lk(mtx); // 条件变量必须配合unique_lock使用，因为unique_lock有lock何unlock函数
        cond.wait(lk, [this]{ return !q.empty(); }); // 当predicate不满足的时候cond释放锁并挂起线程等待，只有当被notify且predicate满足时才重新获得锁继续执行
        const T res = q.front();
        q.pop();
        return res;
    }

private:
    mutex mtx;
    queue<T> q;
    condition_variable cond;
};