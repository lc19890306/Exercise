#include <mutex>
#include <condition_variable>

using namespace std;

class rwlock {
public:
    rwlock() = default;
    ~rwlock() = default;

    void read_lock() {
        unique_lock<mutex> lk(mtx);
        read_cond.wait(lk, [=]{ return writer_cnt == 0; });
        ++reader_cnt;
    }

    void read_unlock() {
        unique_lock<mutex> lk(mtx);
        if (--reader_cnt == 0 && writer_cnt > 0) { // 检查writer_cnt > 0可有可无
            write_cond.notify_one();
        }
    }

    void write_lock() {
        unique_lock<mutex> lk(mtx);
        ++writer_cnt;
        write_cond.wait(lk, [=]{ return reader_cnt == 0 && !is_writing; });
        is_writing = true;
    }

    void write_unlock() {
        unique_lock<mutex> lk(mtx);
        if (--writer_cnt == 0) {
            read_cond.notify_all();
        } else {
            write_cond.notify_one();
        }
        is_writing = false;
    }

private:
    mutex mtx;
    condition_variable read_cond, write_cond;
    atomic_uint32_t reader_cnt{0}, writer_cnt{0};
    atomic_bool is_writing{false};
};

template <typename RWLockable>
class read_lock_guard {
public:
    explicit read_lock_guard(RWLockable &rw_lockable) : rw_lockable(rw_lockable) {
        rw_lockable.read_lock();
    }
    ~read_lock_guard() {
        rw_lockable.read_unlock();
    }

    read_lock_guard() = delete;
    read_lock_guard(const read_lock_guard &) = delete;
    read_lock_guard &operator=(const read_lock_guard &) = delete;

private:
    RWLockable &rw_lockable;
};

template <typename RWLockable>
class write_lock_guard {
public:
    explicit write_lock_guard(RWLockable &rw_lockable) : rw_lockable(rw_lockable) {
        rw_lockable.write_lock();
    }
    ~write_lock_guard() {
        rw_lockable.write_unlock();
    }

    write_lock_guard() = delete;
    write_lock_guard(const write_lock_guard &) = delete;
    write_lock_guard &operator=(const write_lock_guard &) = delete;

private:
    RWLockable &rw_lockable;
};

// #include <mutex>

// using namespace std;

// class rwlock { // 读优先，有任何一个reader在读，则writer挂起
// public:
//     rwlock() : reader_cnt(0) {}
//     void read_lock() {
//         read_mtx.lock();
//         if (++reader_cnt == 1) {
//             write_mtx.lock();
//         }
//         read_mtx.unlock();
//     }
//     void read_unlock() {
//         read_mtx.lock();
//         if (--reader_cnt == 0) {
//             write_mtx.unlock();
//         }
//         read_mtx.unlock();
//     }
//     void write_lock() {
//         write_mtx.lock();
//     }
//     void write_unlock() {
//         write_mtx.unlock();
//     }

// private:
//     mutex read_mtx, write_mtx; // read_mtx控制reader_cnt的读写
//     int reader_cnt;
// };
