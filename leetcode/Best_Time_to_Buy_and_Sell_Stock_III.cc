// DP solution - O(n) time and space complexity
// a variant of max sum of m subarrays, which becomes max sum of AT MOST m subarrays, m in here is 2
// dp[i][j]: max sum of i subarrays of starting j elements, the i-th subarray must contain the j-th element
// prev_max[j]: max(dp[i - 1][i - 1 : j])
// dp[j] = max(dp[j - 1], prev_max[j - 1]) + S[j]
// for exactly m subarrays, target = max(dp[m][m : n])
// in this problem, target = max(dp[1 : m][m : n]), so update max_profit in each iteration
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int n(prices.size());
        vector<int> dp(n + 1), prev_max(n + 1);
        int max_profit(0);
        for (int i(1); i < 3; ++i) {
            auto profit(INT_MIN);
            for (int j(i); j < n; ++j) {
// the array is actally constituted with the difference of prices[j] - prices[j - 1], not prices[j]
                dp[j] = max(dp[j - 1], prev_max[j - 1]) + prices[j] - prices[j - 1];
                prev_max[j - 1] = profit;
                profit = max(profit, dp[j]);
            }
            max_profit = max(max_profit, profit);
        }
        return max_profit;
    }
};

// DP solution - O(n) time and O(1) space complexity
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n(prices.size());
        vector<int> global(3), local(3);
        for (int i(1); i < n; ++i) {
            auto diff(prices[i] - prices[i - 1]);
            for (int j(3); j > 0; --j) {
                local[j] = max(global[j - 1] + max(diff, 0), local[j] + diff);
                global[j] = max(global[j], local[j]);
            }
        }
        return global.back();
    }
};
