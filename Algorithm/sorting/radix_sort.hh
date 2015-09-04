#ifndef RADIX_SORT_HH
#define RADIX_SORT_HH

#include "functions.hh"

#include <vector>

template <typename ForwardIt>
int
maxBit(ForwardIt first, ForwardIt last) {
  auto it(max_element(first, last));
  if (it != last) {
    auto largest(*it);
    auto max_bit(0);
    while (largest > 0) {
      largest /= 10;
      ++max_bit;
    }
    return max_bit;
  }
  return 0;
}

template <typename RandomIt>
void
radix_sort(RandomIt first, RandomIt last) {
  typedef typename std::iterator_traits<RandomIt>::value_type T;
  auto max_bit(maxBit(first, last));
  int radix(1);
  std::vector<std::vector<T> > buckets(10);
  for (int i(0); i != max_bit; ++i) {
    for (auto it(first); it != last; ++it)
      buckets[(*it / radix) % 10].push_back(*it);
    auto it(first);
    for (auto &&bucket : buckets) {
      for (auto &&element : bucket)
	*it++ = element;
      bucket.clear();
    }
    radix *= 10;
  }
}

#endif	// RADIX_SORT_HH
