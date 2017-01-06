// Greedy solution - O(n) time and O(1) space complexity
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty())
            return true;
        int pos(0);
        while (true) {
	  // search for next_pos in current pos' range
	  // the measurement is to find the max_range
            int next_pos(pos);
            for (int i(1), max_range(0); i <= nums[pos] && i < nums.size(); ++i) {
                if (pos + i + nums[pos + i] > max_range) {
                    next_pos = pos + i;
                    max_range = pos + i + nums[pos + i];
                }
            }
            if (next_pos >= nums.size() - 1)
	      // next_pos reaches or even exceed (can cover) the last pos
                return true;
            else if (next_pos == pos)
	      // if current pos' range is 0 (nums[pos] == 0)
                return false;
            pos = next_pos;
        }
        return false;
    }
};
