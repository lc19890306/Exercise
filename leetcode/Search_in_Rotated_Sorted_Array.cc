class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first(0), left(0), right(nums.size() - 1);
        while (left < right) {
            if (nums[left] < nums[right])
                break;
            if (left == right)
                break;
            auto mid((left + right) >> 1);
            if (nums[mid] < nums[right])
                right = mid;
            else
                left = mid + 1;
        }
        first = left;
        if (nums[first] <= target && target <= nums.back())
            return bsearch(nums, first, nums.size(), target);
        else
            return bsearch(nums, 0, first, target);
    }
    
private:
    int bsearch(vector<int> &nums, int first, int last, int target) {
        if (first == last) {
            if (last == nums.size())
                return -1;
            return nums[first] == target ? first : -1;
        }
        auto mid((first + last) >> 1);
	// {3, 1} search 1
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            return bsearch(nums, first, mid, target);
        else
            return bsearch(nums, mid + 1, last, target);
    }
};
