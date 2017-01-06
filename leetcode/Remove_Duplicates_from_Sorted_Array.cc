class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto last(unique(nums.begin(), nums.end()));
        nums.erase(last, nums.end());
        return nums.size();
    }
};

// implement unique
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int i(0), j(i);
        for (; i < nums.size(); ++i)
            if (nums[j] != nums[i] && ++j != i)
                nums[j] = nums[i];
        return ++j;
    }
};
