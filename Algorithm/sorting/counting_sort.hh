#ifndef COUNTING_SORT_HH
#define COUNTING_SORT_HH

#include <vector>
#include <algorithm>

template <typename RandomIt>
void
counting_sort(RandomIt first, RandomIt last) {
  if (first == last)
    return;
  const size_t max_size = 10000;
  std::vector<size_t> count(max_size);
  for (auto it(first); it != last; ++it)
    ++count[*it];
  for (auto it(count.begin() + 1); it != count.end(); ++it)
    *it += it[-1];
  std::vector<size_t> ret(std::distance(first, last));
  for (auto it(last - 1); it >= first; --it)
    ret[--count[*it]] = *it;
  for (auto it(ret.begin()); it != ret.end(); ++it)
    *first++ = *it;
}

#endif	// COUNTING_SORT_HH
