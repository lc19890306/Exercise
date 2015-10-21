// DP solution - O(n^2) time and O(n) space complexity
// Two pointer solution actually
// LIS[i]: the length of longest increasing subsequence ending in i
// for each nums[i], starting from nums[0] (until nums[i-1]), if nums[i] is larger, both LIS[i] and max_len will be updated or not
class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        vector<int> LIS(nums.size(), 1);
        int max_len(0);
        for (int i(1); i < nums.size(); ++i)
            for (int j(0); j < i; ++j) {
                LIS[i] = nums[i] >= nums[j] ? max(LIS[i], LIS[j] + 1) : LIS[i];
                max_len = max(LIS[i], max_len);
            }
        return max_len;
    }
};

// DP solution - O(nlogn) time and O(LIS) space complexity
// LIS[i]: longest increasing subsequence ending in i
class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        vector<int> LIS;
        for (int i(0); i < nums.size(); ++i) {
            auto it(upper_bound(LIS.begin(), LIS.end(), nums[i]));
            if (it != LIS.end())
                *it = nums[i];
            else
                LIS.push_back(nums[i]);
        }
        return LIS.size();
    }
};


