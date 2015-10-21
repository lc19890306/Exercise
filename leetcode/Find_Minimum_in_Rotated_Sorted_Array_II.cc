// Worst case time complexity O(n), O(logn) on average
// the smallest element found may not be the first smallest element right after the largest!!!!
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left(0), right(nums.size() - 1);
        while (left < right) {
            if (nums[left] < nums[right])
                break;
            auto mid((left + right) >> 1);
            if (nums[mid] > nums[right])
                left = mid + 1;
            else if (nums[mid] < nums[right])
                right = mid;
            else
	      // if nums[left] == nums[mid] == nums[right], the minimum could be in the left subarray or the right subarray so the total time complexity will be degraded to O(n)
                --right;
        }
        return nums[left];
    }
};
