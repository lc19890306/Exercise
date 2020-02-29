#include <mutex>

using namespace std;

class rwlock { // 读优先，有任何一个reader在读，则writer挂起
public:
    rwlock() : reader_cnt(0) {}
    void read_lock() {
        read_mtx.lock();
        if (++reader_cnt == 1) {
            write_mtx.lock();
        }
        read_mtx.unlock();
    }
    void read_unlock() {
        read_mtx.lock();
        if (--reader_cnt == 0) {
            write_mtx.unlock();
        }
        read_mtx.unlock();
    }
    void write_lock() {
        write_mtx.lock();
    }
    void write_unlock() {
        write_mtx.unlock();
    }

private:
    mutex read_mtx, write_mtx; // read_mtx控制reader_cnt的读写
    int reader_cnt;
};
