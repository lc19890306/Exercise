#ifndef INSERTION_SORT
#define INSERTION_SORT

#include "functions.hh"

namespace Algo {

template<typename RandomIt>
void
move(RandomIt src, RandomIt dest) {
  if (src < dest)
    for (auto it(src); it != dest; ++it)
      swap(*it, it[1]);
  else
    for (auto it(src); it != dest; --it)
      swap(*it, it[-1]);
}

  template<typename RandomIt, typename SIZE_T>
void
move(RandomIt src, RandomIt dest, const SIZE_T &gap) {
  if (src < dest)
    for (auto it(src); it != dest; it += gap)
      swap(*it, it[gap]);
  else
    for (auto it(src); it != dest; it -= gap)
      swap(*it, it[-gap]);
}

template<typename ForwardIt, typename T>
ForwardIt
lower_bound(ForwardIt first,
	    ForwardIt last,
	    const T &value) {
  auto count(std::distance(first, last));
  while (count > 0) {
    auto it(first);
    auto step(count >> 1);
    std::advance(it, step);
    // Since count/2 always truncates and only affects the right (larget) part,
    // if we want to check the left part, count can be directly set to step,
    // if we want to check the right part, we have to move forward by 1 and
    // minus count by step + 1 to compensate this moving forward
    if (value < *it)
      count = step;
    else {
      // first = it + 1 may be applicable but inappropriate in here
      // because it copies from first, a forward_iterator which does not support random access (it + 1)
      // so ++it is used since forward_iterator supports ++ operation
      first = ++it;
      count -= (step + 1);
    }
  }
  return first;
}

template<typename RandomIt, typename T, typename SIZE_T>
RandomIt
lower_bound(RandomIt first,
	    RandomIt last,
	    const T &value,
	    const SIZE_T &gap) {
  long count(std::distance(first, last) / gap);
  while (count > 0) {
    auto it(first);
    auto step(count >> 1);
    // advance may be of low-efficiency because advance has linear time
    // complexity in most cases except that the iterator it is 
    // a random_access_iterator which supports (it + n) and makes advance
    // run in constant time
    // advance normally reads forward_iterator which only supports ++ operation
    // only if the iterator is a random_access_iterator the time complexity
    // can be reduced to constant
    std::advance(it, step * gap);
    if (value < *it)
      count = step;
    else {
      first = it + gap;
      count -= (step + 1);
    }
  }
  return first;
}

// template<typename ForwardIt, typename T>
// ForwardIt
// lower_bound(ForwardIt first,
// 	       ForwardIt last,
// 	       const T &value) {
//   while (first != last) {
//     auto it(first);
//     auto step(std::distance(first, last) >> 2);
//     std::advance(it, step);
//     if (value < *it)
//       last = it;
//     else
//       first = ++it;
//   }
// // Since the lower bound is usually stands on the right, we return last
// // rather than first
//   return last;
// }

// template<typename ForwardIt, typename T>
// ForwardIt
// lower_bound(ForwardIt first,
// 	       ForwardIt last,
// 	       const T &value) {
//   if (first == last)
//     return last;
//   auto it(first);
//   auto step(std::distance(first, last) >> 2);
//   std::advance(it, step);
//   if (value < *it)
//     return Algo::lower_bound(first, it, value);
//   else
//     return Algo::lower_bound(++it, last, value);
// }

};

template<typename RandomIt>
void
insertion_sort(RandomIt first, RandomIt last) {
  auto begin(first + 1);
  // Since we need to check all the element, we do not use last - 1 as the bound
  while (begin < last) {
    if (*begin < *(begin - 1))
      Algo::move(begin, Algo::lower_bound(first, begin, *begin));
    ++begin;
  }
}

template<typename RandomIt, typename SIZE_T>
void
insertion_sort(RandomIt first, RandomIt last, const SIZE_T &gap) {
  auto begin(first + gap);
  // Since we need to check all the element, we do not use last - 1 as the bound
  while (begin < last) {
    if (*begin < *(begin - gap))
      Algo::move(begin, Algo::lower_bound(first, begin, *begin, gap), gap);
    begin += gap;
  }
}

#endif	// INSERTION_SORT
