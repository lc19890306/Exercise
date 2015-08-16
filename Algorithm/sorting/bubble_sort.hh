#ifndef BUBBLE_SORT
#define BUBBLE_SORT

#include "functions.hh"

template<typename RandomIt>
void
bubble_sort(RandomIt first, RandomIt last) {
  if (first == last)
    return;
  bool sorted(false);
  while (!sorted) {
    --last;
    sorted = true;
    for (auto it(first); it != last; ++it)
      if (*(it + 1) < *it) {
    	swap(*(it + 1), *it);
    	sorted = false;
      }
  }
}

#endif	// BUBBLE_SORT
