#ifndef FUNCTIONS_HH
#define FUNCTIONS_HH

#include <utility>

template <typename T>
void
swap(T &lhs, T &rhs) {
  auto temp(std::move(rhs));
  rhs = std::move(lhs);
  lhs = std::move(temp);
}

namespace Algo {

template<typename ForwardIt>
ForwardIt
min_element(ForwardIt first, 
	    ForwardIt last) {
  if (first == last)
    return last;
  auto smallest(first);
  while (++first != last)
    if (*first < *smallest)
      smallest = first;
  return smallest;
}

template<typename BidirIt>
BidirIt
min_element(BidirIt first, 
	    BidirIt last,
	    bool &sorted) {
  if (first == last)
    return last;
  auto smallest(--last);
  // first has to be set to the sentinel rbegin in order to avoid
  // out of bound error introduced by !=
  --first;
  while (first != --last)
    if (*last < *smallest)
      smallest = last;
    else if (*smallest < *last)
      sorted = false;
  return smallest;
}

template<typename ForwardIt>
ForwardIt
max_element(ForwardIt first, 
	    ForwardIt last) {
  if (first == last)
    return last;
  auto largest(first);
  while (++first != last)
    if (*largest < *first)
      largest = first;
  return largest;
}

template<typename ForwardIt>
ForwardIt
max_element(ForwardIt first, 
	    ForwardIt last,
	    bool &sorted) {
  if (first == last)
    return last;
  auto largest(first);
  while (++first != last)
    if (*largest < *first)
      largest = first;
    else if (*first < *largest)
      sorted = false;
  return largest;
}

// returns the first smallest and largest element
template<typename ForwardIt>
std::pair<ForwardIt, ForwardIt>
minmax_element(ForwardIt first, 
	       ForwardIt last) {
  if (first == last)
    return std::make_pair(first, first);
  auto smallest(first), largest(first);
  while (++first != last) {
    if (*first < *smallest)
      smallest = first;
    if (*largest < *first)
      largest = first;
  }
  return std::make_pair(smallest, largest);
}

template<typename ForwardIt>
std::pair<ForwardIt, ForwardIt>
minmax_element(ForwardIt first, 
	       ForwardIt last,
	       bool &sorted) {
  if (first == last)
    return std::make_pair(first, first);
  auto smallest(first), largest(first);
  while (++first != last) {
    if (*first < *smallest)
      smallest = first;
    if (*largest < *first)
      largest = first;
    else if (*first < *largest)	// only apply to max_element
      sorted = false;
  }
  return std::make_pair(smallest, largest);
}

};


#endif	// FUNCTIONS_HH
