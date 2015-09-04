#ifndef MAIN_HH
#define MAIN_HH

#include "rand_num_generator.hh"
#include "selection_sort.hh"
#include "bubble_sort.hh"
#include "insertion_sort.hh"
#include "cocktail_sort.hh"
#include "minmax_sort.hh"
#include "rank_sort.hh"
#include "shell_sort.hh"
#include "radix_sort.hh"
#include "bucket_sort.hh"
#include "quick_sort.hh"
#include "heap_sort.hh"

#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

typedef std::vector<int>::iterator VIIterator;
typedef void (*SortFunc)(VIIterator, VIIterator);

namespace Algo {

template<typename ForwardIt>
bool
is_sorted(ForwardIt first, ForwardIt last) {
  typedef typename std::iterator_traits<ForwardIt>::value_type T;
  return std::adjacent_find(first, last, std::greater<T>()) == last;
}

};

#endif	// MAIN_HH
