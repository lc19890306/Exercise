// O(n) time complexity
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        auto first(nums.begin());
        for (auto it(nums.begin() + 1); it < nums.end(); ++it) {
            if (*it < it[-1]) {
                first = it;
                break;
            }
        }
        if (*first <= target && target <= nums.back())
            return binary_search(first, nums.end(), target);
        else
            return binary_search(nums.begin(), first, target);
    }
};

// O(n) at worst
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty())
            return false;
        int left(0), right(nums.size() - 1);
        while (left < right) {
            auto mid((left + right) >> 1);
            if (nums[mid] == target)
                return true;
            if (nums[mid] > nums[right])
                if (nums[left] <= target && target < nums[mid])
                    right = mid;
                else
                    left = mid + 1;
            else if (nums[mid] < nums[right])
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid;
            else
                --right;
        }
        return nums[left] == target;
    }
};
