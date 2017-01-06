class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (auto it(nums.rbegin()); it != nums.rend(); ++it) {
            if (*it == val) {
                swap(*it, *nums.rbegin());
		nums.pop_back();
                // nums.erase(nums.end() - 1);
            }
        }
        return nums.size();
    }
};
