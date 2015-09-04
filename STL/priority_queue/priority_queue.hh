#ifndef PRIORITY_QUEUE_HH
#define PRIORITY_QUEUE_HH

#include "algorithm.hh"

#include <vector>

namespace Algo {

  template <typename T,
	    typename Container = std::vector<T> >
  class priority_queue {
  public:
    typedef typename Container::size_type size_type;

    priority_queue() noexcept {}

    virtual ~priority_queue() {
      // clear();
    }

    priority_queue(const priority_queue &other) 
      : container(other.container) {}

    priority_queue & operator = (const priority_queue &rhs) {
      container = rhs.container;
      return *this;
    }

    T top() const {
      return container.front();
    }

    size_type size() const {
      return container.size();
    }

    bool empty() const {
      return container.empty();
    }

    void push(const T &value) {
      container.push_back(value);
      Algo::push_heap(container.begin(), container.end());
    }

    void pop() {
      Algo::pop_heap(container.begin(), container.end());
      container.pop_back();
    }
  private:
    Container container;
  };

};				// namespace Algo

#endif	// PRIORITY_QUEUE_HH
