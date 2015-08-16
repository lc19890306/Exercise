#ifndef STRING_HH
#define STRING_HH

#include <utility>
#include <cstring>
#include <vector>
#include <iostream>

class String {
public:
  typedef std::size_t size_type;
  String() 
    : _len(0),
      _data(nullptr) {}

  String(const char *str)
    : String(str, strlen(str)) {}

  String(const String &other)
    : String(other._data, other._len) {}

  String(String &&other)
    : _len(other._len),
      _data(other._data) {
    other._data = nullptr;
  }

  String &operator = (String rhs) {
    swap(rhs);
    return *this;
  }

  ~String() noexcept {
    delete []_data;
  }

  size_type size() const {
    return _len;
  }

private:
  String(const char *str, const size_type &len)
    : _len(len),
      _data((len > 0) ? new (std::nothrow) char[len + 1] : nullptr) {
    if (_len > 0) {
      if (nullptr == _data) {
	std::cerr << "Error: bad alloc" << std::endl;
	exit(1);
      }
      memcpy(_data, str, _len);
      _data[_len] = 0;
    }
  }

  void swap(String &rhs) {
    std::swap(_len, rhs._len);
    std::swap(_data, rhs._data);
  }

  size_type _len;
  char *_data;
};

// class String
// {
//  public:
//   String() noexcept
//     : data_(nullptr), len_(0)
//   { }

//   ~String()
//   {
//     delete[] data_;
//   }

//   // only read str when len > 0
//   String(const char* str, size_t len)
//     : data_(len > 0 ? new char[len+1] : nullptr), len_(len)
//   {
//     if (len_ > 0)
//     {
//       memcpy(data_, str, len_);
//       data_[len_] = '\0';
//     }
//     else
//     {
//       assert(data_ == nullptr);
//     }
//   }

//   String(const char* str)
//     : String(str, strlen(str))
//   { }

//   String(const String& rhs)
//     : String(rhs.data_, rhs.len_)
//   { }

//   String(String&& rhs) noexcept
//     : data_(rhs.data_), len_(rhs.len_)
//   {
//     rhs.len_ = 0;
//     rhs.data_ = nullptr;
//   }

//   String& operator=(String rhs)
//   {
//     swap(rhs);
//     return *this;
//   }

//   void swap(String& rhs) noexcept
//   {
//     std::swap(len_, rhs.len_);
//     std::swap(data_, rhs.data_);
//   }

//   // const char* data() const { return c_str(); }
//   const char* c_str() const noexcept { return data_ ? data_ : kEmpty; }
//   size_t size() const noexcept { return len_; }

//  private:
//   char* data_;
//   size_t len_;
//   static const char kEmpty[];
// };

#endif	// STRING_HH
