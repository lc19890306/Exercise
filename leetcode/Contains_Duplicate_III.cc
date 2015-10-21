// BST (set) solution - O(nlogk) time and O(k) space complexity
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> table;
        for (int i(0); i < nums.size(); ++i) {
            auto j(i - k - 1);
            if (j >= 0)
                table.erase(nums[j]);
	    // find the minimum element greater than or equal to (nums[i] - t), namely, x >= nums[i] - t
	    // if x < nums[i] then x is found and x - nums[i] must be less than (or equal to) t
	    // if nums[i] < x then we have to check if x - nums[i] is less than or equal to t, if so we find this x
            auto it(table.lower_bound(nums[i] - t));
            if (it != table.end() && *it - nums[i] <= t)
                return true;
            table.insert(nums[i]);
        }
        return false;
    }
};
