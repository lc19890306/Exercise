#ifndef MERGE_SORT_HH
#define MERGE_SORT_HH

#include <vector>
#include <iterator>
#include <algorithm>

namespace Algo {

  template <typename InputIt1, typename InputIt2, typename OutputIt>
  OutputIt
  merge(InputIt1 first1, InputIt1 last1,
	InputIt2 first2, InputIt2 last2,
	OutputIt d_first) {
    while (first1 != last1 && first2 != last2)
      if (*first1 < *first2)
	*d_first++ = *first1++;
      else
	*d_first++ = *first2++;
    return first1 == last1 ? std::copy(first2, last2, d_first) : std::copy(first1, last1, d_first);
  }

};				// namespace Algo

template <typename RandomIt>
void
merge_sort(RandomIt first, RandomIt last) {
  typedef typename std::iterator_traits<RandomIt>::value_type T;
  auto count(std::distance(first, last));
  if (count < 2)
    return;
  auto mid(count >> 1);
  merge_sort(first, first + mid);
  merge_sort(first + mid, last);
  std::vector<T> ret;
  Algo::merge(first, first + mid, first + mid, last, std::back_inserter(ret));
  std::copy(ret.begin(), ret.end(), first);
}

#endif	// MERGE_SORT_HH
