class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i(0); i < nums.size(); ++i) {
            if (!nums[i])
                for (int j(i + 1); j < nums.size(); ++j)
                    if (nums[j]) {
                        swap(nums[i], nums[j]);
                        break;
                    }
        }
    }
};
