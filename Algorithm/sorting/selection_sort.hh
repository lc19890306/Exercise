#ifndef SELECTION_SORT
#define SELECTION_SORT

#include "functions.hh"

// #include <algorithm>

// template<typename RandomIt>
// void
// selection_sort(RandomIt first, RandomIt last) {
//   auto begin(first);
//   // while (begin < last - 1) {
//   // Since min_element has to cover [begin + 1, last), the loop must end
//   // with last - 1 rather than last otherwise min_element will yield
//   // out of bound by covering [last, last)
//   while (begin + 1 < last) {
//     auto it(Algo::min_element(begin + 1, last));
//     if (*it < *begin)
//       swap(*it, *begin);
//     ++begin;
//   }
// }

// Check if sorted when searching for min element
// If so, all the numbers may have been sorted
template<typename RandomIt>
void
selection_sort(RandomIt first, RandomIt last) {
  auto begin(first);
  while (begin + 1 < last) {
    bool sorted(true);
    auto it(Algo::min_element(begin + 1, last, sorted));
    if (*it < *begin)
      swap(*it, *begin);
    else if (sorted)
      return;
    ++begin;
  }
}

#endif	// SELECTION_SORT
