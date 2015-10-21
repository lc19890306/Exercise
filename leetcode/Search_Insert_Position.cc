// Recursive binary search - O(logn) time complexity
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return searchInsert(nums, 0, nums.size(), target);
    }
    
private:
    int searchInsert(vector<int> &nums, int first, int last, int target) {
        if (first == last)
            return last;
        auto mid((first + last) >> 1);
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            return searchInsert(nums, mid + 1, last, target);
        else
            return searchInsert(nums, first, mid, target);
    }
};

// Iterative binary search - O(logn) time complexity and faster than recursive solution
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int first(0), last(nums.size());
        while (first < last) {
            auto mid((first + last) >> 1);
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                first = mid + 1;
            else
                last = mid;
        }
        return last;
    }
};
