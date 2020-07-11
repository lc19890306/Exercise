#pragma once

template<typename T>
class Vector {
public:
    using size_type = std::size_t;
    using value_type = T;

    Vector() : _capacity(0), _size(0), _p(nullptr) {}

    explicit Vector(const size_type size, const value_type &data = value_type())
            : _capacity(size), _size(size), _p(new value_type[_capacity]) {
        std::fill_n(_p, _size, data);
    }

    ~Vector() {
        if (_p) {
            delete[]_p;
            _p = nullptr;
        }
    }

    Vector(const Vector &other)
            : _capacity(other._capacity), _size(other._size), _p(new value_type[_capacity]) {
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
            _p = new value_type[_capacity];
        } else if (_size == _capacity) {
            _capacity *= 2;
            auto p = new value_type[_capacity];
            std::copy_n(_p, _size, p);
            delete []_p;
            _p = p;
        }
        *(_p + _size) = data;
        ++_size;
    }

    [[nodiscard]] bool empty() const {
        return _size == 0;
    }

    void pop_back() {
        if (!empty()) {
            --_size;
            auto t = std::move(*(_p + _size));
        }
    }

private:

    size_type _capacity{};
    size_type _size{};
    value_type *_p;
};
