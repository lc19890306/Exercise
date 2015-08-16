#ifndef BUBBLE_SORT
#define BUBBLE_SORT

#include "functions.hh"

template<typename RandomIt>
void
bubble_sort(RandomIt first, RandomIt last) {
  auto end(last - 1);
  bool sorted(false);
  while (!sorted) {
    sorted = true;
    for (auto it(first); it != end; ++it)
      if (*(it + 1) < *it) {
	swap(*(it + 1), *it);
	sorted = false;
      }
    --end;
  }
}

#endif	// BUBBLE_SORT
