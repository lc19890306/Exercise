// Copy and concatenate at the end of nums, count and take out k nums
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto first(nums.size() - k % nums.size());
        auto last(first + nums.size());        
        nums.insert(nums.end(), nums.begin(), nums.end());
        nums = vector<int>(nums.begin() + first, nums.begin() + last);
    }
};

// Reverse all the nums and then reverse the first k nums and then the last remaining nums
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k % nums.size());
        reverse(nums.begin() + k % nums.size(), nums.end());
    }
};

// Swap the first k nums with the last k nums and shrink the vector by skipping the first k nums
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto n(nums.size());
        for (size_t i(0); k %= n; n -= k, i += k)
            for (size_t j(0); j < k; ++j)
                swap(nums[i + j], nums[nums.size() - k + j]);
    }
};
