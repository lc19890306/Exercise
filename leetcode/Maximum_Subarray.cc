// DP solution - MLE!!! O(n^2) time and space complexity
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<vector<int> > dp(nums.size(), vector<int>(nums.size()));
        for(int i(0); i != nums.size(); ++i)
            dp[i][i] = nums[i];
        int max(nums[0]);
        for (int i(0); i != nums.size() - 1; ++i)
            for (int j(i + 1); j != nums.size(); ++j) {
                dp[i][j] = dp[i][j - 1] + dp[j][j];
                if (dp[i][j] > max)
                    max = dp[i][j];
            }
        return max;
    }
};

// DP solution - O(n) time and O(1) space complexity
// max_end_in[i] = max_end_in[i - 1] < 0 ? nums[i] : max_end_in[i - 1] + nums[i]
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        auto max(nums[0]), max_end_in_here(nums[0]);
        for (int i(1); i != nums.size(); ++i) {
            max_end_in_here = max_end_in_here > 0 ? max_end_in_here + nums[i] : nums[i];
	    // update max in each iteration
            max = std::max(max_end_in_here, max);
        }
        return max;
    }
};

// Divide and conquer solution - O(nlogn) time complexity
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size());
    }
    
private:
    int maxSubArray(vector<int> &nums, int first, int last) {
        if (first == last)
            return INT_MIN;
        if (last - first == 1)
            return nums[first];
        auto mid((first + last) >> 1);
	// 1. if mid is not included in the final range, the final range will be on its left or right
        auto left(maxSubArray(nums, first, mid)), right(maxSubArray(nums, mid + 1, last));
	// 2. if mid is included in the final range, compute the summation of left and right including mid
        auto left_max(nums[mid]), right_max(mid + 1 == last ? INT_MIN : nums[mid + 1]);
        int temp(0);
        for (int i(mid); i >= first; --i) {
            temp += nums[i];
            left_max = max(left_max, temp);
        }
        temp = 0;
        for (int i(mid + 1); i < last; ++i) {
            temp += nums[i];
            right_max = max(right_max, temp);
        }
        int ret;
        if (left_max < 0 && right_max < 0)
            ret = max(left_max, right_max);
        else if (left_max < 0 && right_max >= 0)
            ret = right_max;
        else if (left_max >= 0 && right_max < 0)
            ret = left_max;
        else
            ret = left_max + right_max;
	// 3. compare the three results
        return max(max(left, right), ret);
    }
};
