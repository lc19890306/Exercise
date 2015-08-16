#ifndef COCKTAIL_SORT_HH
#define COCKTAIL_SORT_HH

#include "functions.hh"

template<typename RandomIt>
void
cocktail_sort(RandomIt first, RandomIt last) {
  auto begin(first), end(last - 1);
  bool sorted(false);
  while (!sorted) {
    sorted = true;
    for (auto it(begin); it != end; ++it)
      if (*(it + 1) < *it) {
	swap(*(it + 1), *it);
	sorted = false;
      }
    --end;
    for (auto it(end); it != begin; --it)
      if (*it < *(it - 1)) {
	swap(*it, *(it - 1));
	sorted = false;
      }
    ++begin;
  }
}

#endif	// COCKTAIL_SORT_HH
