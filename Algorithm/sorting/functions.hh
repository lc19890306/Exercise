#ifndef FUNCTIONS_HH
#define FUNCTIONS_HH

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
  auto min_it(first);
  for (auto it(first + 1); it != last; ++it)
    if (*it < *min_it)
      min_it = it;
  return min_it;
}

template<typename ForwardIt>
ForwardIt
min_element(ForwardIt first, 
	    ForwardIt last,
	    bool &sorted) {
  auto min_it(last - 1);
  for (auto it(min_it - 1); it >= first; --it)
    if (*it < *min_it)
      min_it = it;
    else if (*min_it < *it)
      sorted = false;
  return min_it;
}

template<typename ForwardIt>
ForwardIt
max_element(ForwardIt first, 
	    ForwardIt last) {
  auto max_it(first);
  for (auto it(first + 1); it != last; ++it)
    if (*max_it < *it)
      max_it = it;
  return max_it;
}

template<typename ForwardIt>
std::pair<ForwardIt, ForwardIt>
minmax_element(ForwardIt first, 
	       ForwardIt last) {
  auto min_it(first), max_it(first);
  for (auto it(first + 1); it != last; ++it) {
    if (*it < *min_it)
      min_it = it;
    if (*max_it < *it)
      max_it = it;
  }
  return std::make_pair(min_it, max_it);
}

template<typename ForwardIt>
std::pair<ForwardIt, ForwardIt>
minmax_element(ForwardIt first, 
	       ForwardIt last,
	       bool &sorted) {
  auto min_it(first), max_it(first);
  for (auto it(first + 1); it != last; ++it) {
    if (*it < *min_it)
      min_it = it;
    if (*max_it < *it)
      max_it = it;
    else if (*it < *max_it)
      sorted = false;
  }
  return std::make_pair(min_it, max_it);
}

};

#endif	// FUNCTIONS_HH
