#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class SmartPtr;

template <typename T>
class U_Ptr {
    friend class SmartPtr<T>;
    U_Ptr(T *ptr) : p(ptr), count(1) {}
    ~U_Ptr() {
        delete p;
        p = nullptr;
    }
    int count;
    T *p;
};

template <typename T>
class SmartPtr {
public:
    SmartPtr(T *ptr) : rp(new U_Ptr<T>(ptr)) {}
    SmartPtr(const SmartPtr &other) : rp(other.rp) {
        ++rp->count;
    }
    SmartPtr &operator=(const SmartPtr &rhs) {
        ++rhs.rp->count;
        decCount();
        rp = rhs.rp;
        return *this;
    }
    ~SmartPtr() {
        decCount();
    }
    T &operator*() const {
        return *(rp->p);
    }
    T *operator->() const {
        return rp->p;
    }
    operator bool() const {
        return rp;
    }

private:
    void decCount() {
        if (--rp->count == 0) {
            delete rp;
            rp = nullptr;
        }
    }
    U_Ptr<T> *rp;
};

/*
#include <utility>  // std::swap

class shared_count {
public:
    shared_count() noexcept
            : count_(1) {}
    void add_count() noexcept
    {
        ++count_;
    }
    long reduce_count() noexcept
    {
        return --count_;
    }
    long get_count() const noexcept
    {
        return count_;
    }

private:
    long count_;
};

template <typename T>
class smart_ptr {
public:
    template <typename U>
    friend class smart_ptr;

    explicit smart_ptr(T* ptr = nullptr)
            : ptr_(ptr)
    {
        if (ptr) {
            shared_count_ =
                    new shared_count();
        }
    }
    ~smart_ptr()
    {
        if (ptr_ &&
            !shared_count_
                    ->reduce_count()) {
            delete ptr_;
            delete shared_count_;
        }
    }

    smart_ptr(const smart_ptr& other)
    {
        ptr_ = other.ptr_;
        if (ptr_) {
            other.shared_count_
                    ->add_count();
            shared_count_ =
                    other.shared_count_;
        }
    }
    template <typename U>
    smart_ptr(const smart_ptr<U>& other) noexcept
    {
        ptr_ = other.ptr_;
        if (ptr_) {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }
    template <typename U>
    smart_ptr(smart_ptr<U>&& other) noexcept
    {
        ptr_ = other.ptr_;
        if (ptr_) {
            shared_count_ =
                    other.shared_count_;
            other.ptr_ = nullptr;
        }
    }
    template <typename U>
    smart_ptr(const smart_ptr<U>& other,
              T* ptr) noexcept
    {
        ptr_ = ptr;
        if (ptr_) {
            other.shared_count_
                    ->add_count();
            shared_count_ =
                    other.shared_count_;
        }
    }
    smart_ptr&
    operator=(smart_ptr rhs) noexcept
    {
        rhs.swap(*this);
        return *this;
    }

    T* get() const noexcept
    {
        return ptr_;
    }
    long use_count() const noexcept
    {
        if (ptr_) {
            return shared_count_
                    ->get_count();
        } else {
            return 0;
        }
    }
    void swap(smart_ptr& rhs) noexcept
    {
        using std::swap;
        swap(ptr_, rhs.ptr_);
        swap(shared_count_,
             rhs.shared_count_);
    }

    T& operator*() const noexcept
    {
        return *ptr_;
    }
    T* operator->() const noexcept
    {
        return ptr_;
    }
    operator bool() const noexcept
    {
        return ptr_;
    }

private:
    T* ptr_;
    shared_count* shared_count_;
};

template <typename T>
void swap(smart_ptr<T>& lhs,
          smart_ptr<T>& rhs) noexcept
{
    lhs.swap(rhs);
}

template <typename T, typename U>
smart_ptr<T> static_pointer_cast(
        const smart_ptr<U>& other) noexcept
{
    T* ptr = static_cast<T*>(other.get());
    return smart_ptr<T>(other, ptr);
}

template <typename T, typename U>
smart_ptr<T> reinterpret_pointer_cast(
        const smart_ptr<U>& other) noexcept
{
    T* ptr = reinterpret_cast<T*>(other.get());
    return smart_ptr<T>(other, ptr);
}

template <typename T, typename U>
smart_ptr<T> const_pointer_cast(
        const smart_ptr<U>& other) noexcept
{
    T* ptr = const_cast<T*>(other.get());
    return smart_ptr<T>(other, ptr);
}

template <typename T, typename U>
smart_ptr<T> dynamic_pointer_cast(
        const smart_ptr<U>& other) noexcept
{
    T* ptr = dynamic_cast<T*>(other.get());
    return smart_ptr<T>(other, ptr);
}
 */

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template <typename T>
class smart_ptr {
public:
    smart_ptr(T *ptr = nullptr) : p(ptr) {
        if (ptr) {
            count = new size_t(1);
        }
    }
    ~smart_ptr() {
        dec_count();
    }
    smart_ptr(const smart_ptr &other) {
        p = other.p;
        if (p) {
            ++*(other.count);
            count = other.count;
        }
    }
    smart_ptr(smart_ptr &&other) {
        p = other.p;
        if (p) {
            count = other.count;
            other.p = nullptr; // 一定要置空！！避免count在other中被destroy
        }
    }
    smart_ptr &operator=(const smart_ptr &rhs) {
        if (this != &rhs) {
            dec_count();
            p = rhs.p;
            if (p) {
                ++*(rhs.count);
                count = rhs.count;
            }
        }
        return *this;
    }
    smart_ptr &operator=(smart_ptr &&rhs) {
        dec_count();
        p = rhs.p;
        count = rhs.count;
        rhs.p = nullptr;
        return *this;
    }
//    smart_ptr &operator=(smart_ptr rhs) {
//        rhs.swap(*this);
//        return *this;
//    }
//    void swap(smart_ptr &rhs) {
//        using std::swap;
//        swap(p, rhs.p);
//        swap(count, rhs.count);
//    }
    T *get() const {
        return p;
    }
    size_t use_count() const {
        return p ? *count : 0;
    }
    T &operator*() const {
        return *p;
    }
    T *operator->() const {
        return p;
    }
    operator bool() const {
        return p;
    }

private:
    void dec_count() {
        if (p && --*count == 0) {
            delete p;
            delete count;
        }
    }
    T *p;
    size_t *count;
};

int main() {
    using T = smart_ptr<int>;
//    using T = shared_ptr<int>;
    T p1(new int(2));
    cout << "p1.use_count(): " << p1.use_count() << endl;
    cout << *p1 << endl;
    *p1 = 5;
    cout << *p1 << endl;
    {
        T p2(p1), p3(new int(5));
        cout << "p1.use_count(): " << p1.use_count() << endl;
        cout << "p2.use_count(): " << p2.use_count() << endl;
        cout << "p3.use_count(): " << p3.use_count() << endl;
        p2 = std::move(p3);
        cout << "p1.use_count(): " << p1.use_count() << endl;
        cout << "p2.use_count(): " << p2.use_count() << endl;
        cout << "p3.use_count(): " << p3.use_count() << endl;
    }
    cout << "p1.use_count(): " << p1.use_count() << endl;
    return 0;
}
