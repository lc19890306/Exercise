#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// DP solution - O(n^2) time and O(n) space complexity
// bitonic sequence is a sequence first in ascending order and then in descending order
int longestBitonicSequence(const vector<int> &nums) {
  int n(nums.size());
  vector<int> LIS_forwards(n, 1), LIS_backwards(n, 1);
  // compute longest increasing sequence left to right
  for (int i(1); i < n; ++i)
    for (int j(0); j < i; ++j)
      if (nums[i] >= nums[j])
	LIS_forwards[i] = max(LIS_forwards[i], LIS_forwards[j] + 1);
  // compute longest increasing sequence right to left
  for (int i(n - 2); i >= 0; --i)
    for (int j(n - 1); j > i; --j)
      if (nums[i] >= nums[j])
	LIS_backwards[i] = max(LIS_backwards[i], LIS_backwards[j] + 1);
  // for each i, LIS_forwards[i] is the longest increasing sequence in ascending order until i, while LIS_backwards[i] is the longest increasing sequence in descending order until i
  // add LIS_forwards[i] and LIS_backwards[i] and then minus 1 for the duplicated nums[i] (count twice)
  // update the summation for the maximum one
  int ret(0);
  for (int i(0); i < n; ++i) {
    LIS_forwards[i] += (LIS_backwards[i] - 1);
    ret = max(ret, LIS_forwards[i]);
  }
  return ret;
}

int main() {
  vector<int> nums{2, -1, 4, 3, 5, -1, 3, 2};
  auto ret(longestBitonicSequence(nums));
  cout << ret << endl;
  return 0;
}
