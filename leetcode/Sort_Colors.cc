// O(n) time and O(1) space complexity
class Solution {
public:
    void sortColors(vector<int>& nums) {
        auto it(partition(nums.begin(), nums.end(), [](int i){return i < 2;}));
        partition(nums.begin(), it, [](int i){return i == 0;});
    }
};

// O(n) time and O(1) space complexity
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3);
        for (auto &&num : nums)
            ++count[num];
        int i(0);
        for (auto it(nums.begin()); i < 3; ++i)
            it = fill_n(it, count[i], i);
    }
};

// O(n) time and O(1) space complexity
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty())
            return;
        int idx_0(0), idx_2(nums.size() - 1);
        for (int i(0); i <= idx_2; ++i) {
	  // CANNOT REVERSE ORDER!!! Because for loop ends with comparing i with idx_2
	  // if while loop for 0 comes first, the final while loop for 0 may be abandonned due to the ending comparison between i and idx_2
            while (2 == nums[i] && i < idx_2)
                swap(nums[i], nums[idx_2--]);
            while (0 == nums[i] && idx_0 < i)
                swap(nums[i], nums[idx_0++]);
        }
    }
};
