#ifndef MINMAX_SORT_HH
#define MINMAX_SORT_HH

#include "functions.hh"

// ONLY APPLY TO EVEN NUMBER!!!!!!!
// template<typename RandomIt>
// void
// minmax_sort(RandomIt first, RandomIt last) {
//   auto begin(first), end(last - 1), mid(first + std::distance(begin, end) / 2);
//   while (begin < end) {
//     if (*end < *begin)
//       swap(*begin, *end);
//     ++begin;
//     --end;
//   }

//   begin = first;
//   end = last - 1;
//   while (begin < end) {
//     auto min_it(Algo::min_element(begin, mid + 1));
//     auto max_it(Algo::max_element(mid + 1, end + 1));
//     auto dist_min(std::distance(begin, min_it));
//     auto dist_max(std::distance(max_it, end));
//     if (*min_it < *begin)
//       swap(*min_it, *begin);
//     if (*end < *max_it)
//       swap(*end, *max_it);
//     if (*(end - dist_min) < *min_it)
//       swap(*(end - dist_min), *min_it);
//     if (*max_it < *(last - dist_max))
//       swap(*max_it, *(last - dist_max));
//     ++begin;
//     --end;
//   }
// }

template<typename RandomIt>
void minmax_sort(RandomIt first, RandomIt last) {
  --last;
  while (first < last) {
    bool sorted(true);
    auto minmax_pair(Algo::minmax_element(first, last + 1, sorted));
    if (sorted)
      return;
    auto min_it(minmax_pair.first), max_it(minmax_pair.second);
    if (first == max_it && last == min_it)
      swap(*min_it, *max_it);
    else if (first == max_it) {
      swap(*last, *max_it);
      swap(*first, *min_it);
    }
    else {
      swap(*first, *min_it);
      swap(*last, *max_it);
    }
    ++first;
    --last;
  }
}

#endif	// MINMAX_SORT_HH
