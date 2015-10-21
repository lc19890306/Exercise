// DP solution - O(k*n) time and O(n) space complexity
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n(prices.size());
        if (n < 1 || k == 0)
            return 0;
	// if k >= n/2, this problem becomes Best Time to Buy and Sell Stock II, which uses greedy algorithm, this is because this problem is not exactly the same as max sum of k subarrays, it is actually max sum of AT MOST k subarrays, so if any consecutive element are positive, which can be added to the final summation, the number of subarrays is actually less than k, in other words, two consecutive subarrays can be merged into one, therefore the maximum number of subarrays is just n/2, which is like {-1, 1, -1, 1, -1 ...}, then if k >= n/2, the maximum number of subarrays is less than k and this problem becomes "you can complete as many transactions as you want"
        if (k >= (n >> 1)) {
            int max_profit(0);
            for (int i(1); i < n; ++i)
                max_profit += (prices[i] > prices[i - 1] ? prices[i] - prices[i - 1] : 0);
            return max_profit;
        }
	// almost the same as Best Time to Buy and Sell Stock III except for the limit k
        vector<int> dp(n + 1), prev_max(n + 1);
        int max_profit(0);
        for (int i(1); i <= k; ++i) {
            int profit(INT_MIN);
            for (int j(i); j < n; ++j) {
                dp[j] = max(dp[j - 1], prev_max[j - 1]) + prices[j] - prices[j - 1];
                prev_max[j - 1] = profit;
                profit = max(profit, dp[j]);
            }
            max_profit = max(max_profit, profit);
        }
        return max_profit;
    }
};
