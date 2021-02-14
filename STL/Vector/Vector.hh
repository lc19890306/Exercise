#pragma once

#include <algorithm>

template<typename T>
class Vector {
public:
    using size_type = std::size_t;
    using value_type = T;

    Vector() : _capacity(0), _size(0), _p(nullptr) {}

    explicit Vector(const size_type size, const value_type &data = value_type())
            : _capacity(size), _size(size) {
        _capacity = resolve(_capacity);
        _p = static_cast<value_type *>(malloc(sizeof(value_type) * _capacity));
        for (size_type i = 0; i < _size; ++i) {
            new(_p + i)value_type(data);
        }
    }

    ~Vector() {
        free_mem();
        _size = 0;
    }

    Vector(const Vector &other)
            : _capacity(other._capacity), _size(other._size), _p(static_cast<value_type *>(malloc(sizeof(value_type) * _capacity))) {
        std::copy_n(other._p, other._size, _p);
    }

    Vector(Vector &&other) noexcept: _capacity(other._capacity), _size(other._size), _p(other._p) {
        other._p = nullptr;
    }

    Vector &operator=(Vector rhs) {
        swap(rhs);
        return *this;
    }

    void swap(Vector &other) {
        std::swap(_capacity, other._capacity);
        std::swap(_size, other._size);
        std::swap(_p, other._p);
    }

    [[nodiscard]] size_type size() const {
        return _size;
    }

    [[nodiscard]] size_type capacity() const {
        return _capacity;
    }

    value_type &operator[](const size_type idx) const {
        return *(_p + idx);
    }

    [[nodiscard]] value_type &at(const size_type idx) const {
        if (idx < 0 || idx >= _size) {
            throw std::out_of_range("Out of bound");
        }
        return *(_p + idx);
    }

    void push_back(const value_type &data) {
        if (0 == _capacity) {
            _capacity = 1;
            _p = static_cast<value_type *>(malloc(sizeof(value_type) * _capacity));
        } else if (_size == _capacity) {
            _capacity *= 2;
            auto p = static_cast<value_type *>(malloc(sizeof(value_type) * _capacity));
            std::copy_n(_p, _size, p);
            free_mem();
            _p = p;
        }
        new(_p + _size)value_type(data);
        ++_size;
    }

    template<typename... Args>
    void emplace_back(Args&&... args) {
        if (0 == _capacity) {
            _capacity = 1;
            _p = static_cast<value_type *>(malloc(sizeof(value_type) * _capacity));
        } else if (_size == _capacity) {
            _capacity *= 2;
            auto p = static_cast<value_type *>(malloc(sizeof(value_type) * _capacity));
            std::copy_n(_p, _size, p);
            free_mem();
            _p = p;
        }
        new(_p + _size)value_type(std::forward<Args>(args)...);
        ++_size;
    }

    [[nodiscard]] bool empty() const {
        return _size == 0;
    }

    void pop_back() {
        if (!empty()) {
            --_size;
            (_p + _size)->~value_type();
//             auto t = std::move(*(_p + _size));
        }
    }

private:

    void free_mem() {
        if (_p) {
            for (size_type i = 0; i < _size; ++i) {
                (_p + i)->~value_type();
//                 auto t = move(*(_p + i));
            }
            free(_p);
            _p = nullptr;
        }
    }

    size_type resolve(size_type capacity) {
        if (capacity == 0) return 0;
        if ((capacity & (capacity - 1)) == 0) return capacity;
        size_type new_capacity = 1;
        while (capacity > 0) {
            new_capacity <<= 1;
            capacity >>= 1;
        }
        return new_capacity;
    }

    size_type _capacity{};
    size_type _size{};
    value_type *_p{};
};
