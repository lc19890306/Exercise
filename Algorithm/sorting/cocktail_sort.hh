#ifndef COCKTAIL_SORT_HH
#define COCKTAIL_SORT_HH

#include "functions.hh"

template<typename RandomIt>
void
cocktail_sort(RandomIt first, RandomIt last) {
  if (first == last)
    return;
  // auto begin(first), end(last - 1);
  --last;
  bool sorted(false);
  while (!sorted) {
    sorted = true;
    for (auto it(first); it != last; ++it)
      if (*(it + 1) < *it) {
	swap(*(it + 1), *it);
	sorted = false;
      }
    --last;
    for (auto it(last); it != first; --it)
      if (*it < *(it - 1)) {
	swap(*it, *(it - 1));
	sorted = false;
      }
    ++first;
  }
}

#endif	// COCKTAIL_SORT_HH
