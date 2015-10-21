#include "swap.hh"

#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

namespace Algo {

// template <typename ForwardIt>
// ForwardIt
// partition(ForwardIt first, ForwardIt last) {
//   if (first == last)
//     return last;
//   srand((unsigned)time(NULL));
//   int count(distance(first, last));
//   auto pivot(first[rand() % count]);
//   while (true) {
//     while (first < last && *first < pivot)
//       ++first;
//     if (first == last--)
//       break;
//     while (first < last && pivot <= *last)
//       --last;
//     if (first == last)
//       break;
//     iter_swap(first++, last);
//   }
//   return first;
// }

// template <typename RandomIt>
// void
// nth_element(RandomIt first, RandomIt nth, RandomIt last) {
//   while (first < last) {
//     auto it(partition(first, last));
//     if (nth < it)
//       last = it;
//     else if (nth == it)
//       return;
//     else
//       first = it;
//   }
// }

int
partition(vector<int> &vec, int first, int last) {
  if (first == last)
    return last;
  // srand((unsigned)time(NULL));
  int count(last - first);
  auto pivot(vec[first + (count >> 1)]);
  while (true) {
    while (first < last && vec[first] < pivot)
      ++first;
    if (first == last--)
      break;
    while (first < last && pivot < vec[last])
      --last;
    if (first == last)
      break;
    swap(vec[first], vec[last]);
  }
  return first;
}

void
nth_element(vector<int> &vec, int first, int nth, int last) {
  while (first < last) {
    auto it(partition(vec, first, last));
    if (nth < it)
      last = it;
    else if (nth == it)
      return;
    else
      first = it;
  }
}

};				// namespace Algo

int main() {
  vector<int> vec{4, 10, 9, 0, 1, 4, 5, 5, 6, 3}, vec1{4, 10, 9, 0, 1, 4, 5, 5, 6, 3};
  int idx(8);
  nth_element(vec.begin(), vec.begin() + idx, vec.end());
  cout << vec[idx] << endl;
  Algo::nth_element(vec1, 0, idx, vec1.size());
  // Algo::nth_element(vec1.begin(), vec1.begin() + idx, vec1.end());
  cout << vec1[idx] << endl;
  return 0;
}
