#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
#include <queue>

#include "thread_safe_queue.hpp"

class join_threads {
public:
    explicit join_threads(std::vector<std::thread> &threads) : _threads(threads) {}

    ~join_threads() {
        for (auto &thread : _threads) {
            if (thread.joinable()) {
                thread.join();
            }
        }
    }

private:
    std::vector<std::thread> &_threads;
};

class thread_pool {
public:
    thread_pool() : _done(false), _joiner(_threads) {
        const unsigned thread_count = std::thread::hardware_concurrency();
        try {
            for (unsigned i = 0; i < thread_count; ++i) {
                _threads.push_back(std::thread(&thread_pool::worker_thread, this));
            }
        } catch (...) {
            _done = true;
            throw; // rethrows the exception object
        }
    }

    ~thread_pool() {
        _done = true;
    }

    template<typename Fcn>
    void submit(Fcn f) {
        _work_queue.push(std::function<void()>(f));
    }

private:
    void worker_thread() {
        while (!_done) {
            std::function<void()> task;
            if (_work_queue.try_pop(task)) {
                task();
            } else {
                std::this_thread::yield();
            }
        }
    }

    std::atomic_bool _done;
    thread_safe_queue<std::function<void()>> _work_queue;
    std::vector<std::thread> _threads;
    join_threads _joiner;
};
