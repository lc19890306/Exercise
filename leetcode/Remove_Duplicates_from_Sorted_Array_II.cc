// O(n) time and O(1) space complexity
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i(0);
        for (auto &&num : nums)
            if (i < 2 || num > nums[i - 2])
                nums[i++] = num;
        return i;
    }
};

// can be extended to at most k duplicates
class Solution {
public:
  int removeDuplicates(vector<int>& nums, int k) {
        int i(0);
        for (auto &&num : nums)
            if (i < k || num > nums[i - k])
                nums[i++] = num;
        return i;
    }
};
