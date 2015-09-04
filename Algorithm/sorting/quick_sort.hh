#ifndef QUICK_SORT_HH
#define QUICK_SORT_HH

#include <stack>

template <typename InputIt>
InputIt
median(InputIt first, InputIt mid, InputIt last) {
  if (*first <= *mid && *mid <= *last)
    return mid;
  if (*first <= *last && *last <= *mid)
    return last;
  if (*mid <= *first && *first <= *last)
    return first;
  if (*mid <= *last && *last <= *first)
    return last;
  if (*last <= *mid && *mid <= *first)
    return mid;
  if (*last <= *first && *first <= *mid)
    return first;
  return mid;
}

template <typename RandomIt>
RandomIt
partition(RandomIt first, RandomIt last) {
  auto pivot(last - 1);
  auto left(first), right(last - 2);
  while (left < right) {
    while (left < right && *left <= *pivot)
      ++left;
    while (left < right && *pivot <= *right)
      --right;
    swap(*left, *right);
  }
  if (*left <= *pivot) {
    swap(left[1], *pivot);
    return left + 1;
  }
  else {
    swap(*left, *pivot);
    return left;
  }
}

// Recursive version
template <typename RandomIt>
void
quick_sort(RandomIt first, RandomIt last) {
  auto count(distance(first, last));
  if (count < 2)
    return;
  swap(*median(first, first + (count >> 1), last - 1), last[-1]);
  auto pivot(partition(first, last));
  quick_sort(first, pivot);
  quick_sort(pivot + 1, last);
}

// // Iterative version -- almost the SAME as the recursive version
// template <typename RandomIt>
// struct Range {
//   Range(RandomIt first, RandomIt last)
//     : first(first),
//       last(last) {}
//   RandomIt first;
//   RandomIt last;
// };

// template <typename RandomIt>
// void
// quick_sort(RandomIt first, RandomIt last) {
//   std::stack<Range<RandomIt> > s;
//   s.push(Range<RandomIt>(first, last));
//   while (!s.empty()) {
//     auto range(s.top());
//     s.pop();
//     auto count(distance(range.first, range.last));
//     if (count < 2)
//       continue;
//     swap(*median(range.first, range.first + (count >> 1), range.last - 1), range.last[-1]);
//     auto pivot(partition(range.first, range.last));
//     s.push(Range<RandomIt>(range.first, pivot));
//     s.push(Range<RandomIt>(pivot + 1, range.last));
//   }
// }

#endif	// QUICK_SORT_HH
