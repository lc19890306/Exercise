#ifndef SHELL_SORT_HH
#define SHELL_SORT_HH

#include "insertion_sort.hh"

#include <algorithm>
#include <vector>
#include <cmath>

template<typename T>
void
gen_gaps(std::vector<T> &gaps, const std::size_t &num) {
  std::size_t size(std::log((num << 1) + 1) / std::log(3));
  for (auto i(size); i != 0; --i) {
    auto gap(long(std::pow(3, i) - 1) >> 1);
    gaps.push_back(gap);
  }
}

template<typename RandomIt>
void
shell_sort(RandomIt first, RandomIt last) {
  // if (first == last)
  //   return;
  auto count(std::distance(first, last));
  std::vector<long> gaps;
  gen_gaps(gaps, count);
  for (auto &&gap : gaps) {
    for (std::size_t i(0); i != gap; ++i)
      insertion_sort(first + i, last, gap);
  }
}

#endif	// SHELL_SORT_HH
