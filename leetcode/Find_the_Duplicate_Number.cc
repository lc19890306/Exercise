// Share the same idea with Linked List Cycle II
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.empty())
            return -1;
        int slow(nums[0]), fast(nums[nums[0]]);
	// meet in some place
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
	// let two pointers start from front and meet place, repectively
        fast = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
