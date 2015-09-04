#ifndef HEAP_SORT_HH
#define HEAP_SORT_HH

#include "functions.hh"

namespace Algo {

template <typename RandomIt>
bool
is_heap(RandomIt first, RandomIt last) {
  std::size_t i(0);
  auto count(distance(first, last));
  while (++i <= (count >> 1))
    if (first[i - 1] < first[(i << 1) - 1] || first[i - 1] < first[i << 1])
      return false;
  return true;
}

  template <typename RandomIt>
RandomIt
  is_heap_until(RandomIt first, RandomIt last) {
    std::size_t i(0);
    auto count(distance(first, last));
    while (++i <= (count >> 1))
      if (first[i - 1] < first[(i << 1) - 1])
	return first + (i << 1) - 1;
      else if (first[i - 1] < first[i << 1])
	return first + (i << 1);
    return last;
  }

  template <typename RandomIt>
void
  push_heap(RandomIt first, RandomIt last) {
    if (first == last)
      return;
    auto count(distance(first, last));
    std::size_t i(count);
    while (--i > 0)
      if (first[i] > first[(i - 1) >> 1])
	Algo::swap(first[i], first[(i - 1) >> 1]);
  }

  template <typename RandomIt>
void
  pop_heap(RandomIt first, RandomIt last) {
    if (first == last)
      return;
    Algo::swap(*first, last[-1]);
    std::size_t i(0);
    auto count(distance(first, last) - 1);
    while (++i <= (count >> 1)) {
      if (first[i - 1] < first[(i << 1) - 1]) {
	if (first + (i << 1) == last)
	  return;
	Algo::swap(first[i - 1], first[(i << 1) - 1]);
      }
      if (first[i - 1] < first[i << 1]) {
	if (first + (i << 1) == last - 1)
	  return;
	Algo::swap(first[i - 1], first[i << 1]);
      }
    }
  }

  template <typename RandomIt>
void
  make_heap(RandomIt first, RandomIt last) {
    auto it(first);
    while (++it <= last)
      Algo::push_heap(first, it);
  }

  template <typename RandomIt>
void
  sort_heap(RandomIt first, RandomIt last) {
    while (first != last)
      Algo::pop_heap(first, last--);
  }

};				// namespace Algo

template <typename RandomIt>
void
heap_sort(RandomIt first, RandomIt last) {
  Algo::make_heap(first, last);
  Algo::sort_heap(first, last);
}

#endif	// HEAP_SORT_HH
