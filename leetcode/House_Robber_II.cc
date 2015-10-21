// DP solution - O(n) time and space complexity
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<vector<int> > money(nums.size(), vector<int>(2));
	// if not rob the first house
        money[0][0] = money[0][1] = 0;
        for (int i(1); i < money.size(); ++i) {
            money[i][0] = max(money[i - 1][0], money[i - 1][1]);
            money[i][1] = money[i - 1][0] + nums[i];
        }
        auto money_not_rob_first(max(money.back()[0], money.back()[1]));
	// if rob the first house
        money[0][1] = nums[0];
        if (nums.size() > 1) {
            money[1][0] = nums[0];
            money[1][1] = 0;
        }
        for (int i(2); i + 1 < nums.size(); ++i) {
            money[i][0] = max(money[i - 1][0], money[i - 1][1]);
            money[i][1] = money[i - 1][0] + nums[i];
        }
        auto money_rob_first(money.size() > 1 ? max(money[money.size() - 2][0], money[money.size() - 2][1]) : nums[0]);
	// compare two cases
        return max(money_not_rob_first, money_rob_first);
    }
};

// Optimized DP solution - O(n) time and O(1) space complexity
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        total_rob = total_not_rob = 0;
        auto money_not_rob_first(rob(nums, 1, nums.size()));
        total_rob = 0;
        total_not_rob = nums[0];
        auto money_rob_first(nums.size() > 1 ? rob(nums, 2, nums.size() - 1) : nums[0]);
        return max(money_not_rob_first, money_rob_first);
    }
    
private:
    int rob(vector<int> &nums, int l, int r) {
        for (int i(l); i < r; ++i) {
            auto total_not_rob_prev(total_not_rob);
            total_not_rob = max(total_not_rob, total_rob);
            total_rob = total_not_rob_prev + nums[i];
        }
        return max(total_rob, total_not_rob);
    }
    
    int total_rob;
    int total_not_rob;
};
