// O(n) time complexity
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size(nums.size());
        nums.push_back(INT_MIN);
        for (int i(1); i < size; ++i)
            if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1])
                return i;
        return 0;
    }
};

// Binary search solution - O(logn) time complexity
// because nums[i] != nums[i + 1], nums is locally sorted and therefore can be applied with bianry search
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size(nums.size());
        nums.push_back(INT_MIN);
        int l(1), r(size - 1);
        while (l <= r) {
            auto mid((l + r) >> 1);
            if (nums[mid - 1] < nums[mid] && nums[mid + 1] < nums[mid])
                return mid;
            else if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return r;
    }
};
