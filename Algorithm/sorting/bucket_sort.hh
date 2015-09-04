#ifndef BUCKET_SORT_HH
#define BUCKET_SORT_HH

#include "functions.hh"

#include <algorithm>

template <typename RandomIt>
void
bucket_sort(RandomIt first, RandomIt last) {
  auto count(distance(first, last));
  if (count < 2)
    return;
  auto minmax_pair(minmax_element(first, last));
  auto smallest(*(minmax_pair.first)), largest(*(minmax_pair.second));
  auto bucket_count(std::min(count, (long)10));
  typedef typename std::iterator_traits<RandomIt>::value_type T;
  std::vector<std::vector<T> > buckets(bucket_count);
  // Since the bucket index is zero-based, we have to add 1 additionally
  // in order to make the smallest / bucket_size equal 0
  auto bucket_size((largest - smallest) / bucket_count + smallest + 1);
  for (auto it(first); it != last; ++it)
    buckets[*it / bucket_size].push_back(*it);
  for (auto &&bucket : buckets)
    bucket_sort(bucket.begin(), bucket.end());
  auto it(first);
  for (auto &&bucket : buckets)
    for (auto &&element : bucket)
      *it++ = element;
}

#endif	// BUCKET_SORT_HH
