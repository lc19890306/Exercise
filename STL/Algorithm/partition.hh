#ifndef PARTITION_HH
#define PARTITION_HH

#include "iter_swap.hh"

namespace Algo {

  template <class BidirIt, class UnaryPredicate>
  BidirIt partition(BidirIt first, BidirIt last, UnaryPredicate p) {
    while (true) {
      while (first != last && p(*first)) ++first;
      if (first == last--) break;
      while (first != last && !p(*last)) --last;
      if (first == last) break;
      Algo::iter_swap(first++, last);
    }
    return first;
  }

  // For nth_element, sort, etc.
  template <class BidirIt, class T>
  BidirIt partition(BidirIt first, BidirIt last, T p) {
    while (true) {
      // using *first <= pivot is faulty
      while (first != last && *first < pivot) ++first;
      if (first == last--) break;
      while (first != last && pivot < *last) --last;
      if (first == last) break;
      Algo::iter_swap(first++, last);
    }
    return first;
  }

};				// namespace Algo

#endif	// PARTITION_HH
