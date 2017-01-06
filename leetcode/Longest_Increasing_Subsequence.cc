// DP solution - O(nlogn) time and O(k) space complexity, where k is the final result
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (auto &&num : nums) {
	  // use lower_bound not upper_bound
	  // case: 2, 2
            auto it(lower_bound(dp.begin(), dp.end(), num));
            if (it == dp.end())
                dp.push_back(num);
            else
                *it = num;
        }
        return dp.size();
    }
};
