#ifndef RANK_SORT_HH
#define RANK_SORT_HH

#include <vector>

template<typename InputRandomIt, typename OutputRandomIt>
void
set_rank(InputRandomIt first, InputRandomIt last, OutputRandomIt d_first) {
  auto count(std::distance(first, last));
  for (auto i(0); i != count - 1; ++i)
    for (auto j(i + 1); j != count; ++j)
      if (first[i] <= first[j])
	++d_first[j];
      else
	++d_first[i];
}

template<typename RandomIt, typename InputRandomIt>
void rearrange(RandomIt first, RandomIt last, InputRandomIt d_first) {
  auto count(std::distance(first, last));
  std::size_t i(0);
  while (i != count - 1) {
    // auto rank(d_first[i]) is incorrect in here because
    // swap(d_first[*rank_it], *rank_it) requires a dereferenced iterator
    // rather than an instant value rank
    auto rank_it(d_first + i);
    if (*rank_it != i) {
      swap(first[*rank_it], first[i]);
      swap(d_first[*rank_it], *rank_it);
    }
    else
      ++i;
  }
}

template<typename RandomIt>
void
rank_sort(RandomIt first, RandomIt last) {
  auto count(std::distance(first, last));
  std::vector<long> rank(count, 0);
  set_rank(first, last, rank.begin());
  rearrange(first, last, rank.begin());
}

#endif	// RANK_SORT_HH
