// DP solution - O(n) time and space complexity
// dp[i][0]: current "first" player's total value
// dp[i][1]: current "second" player's total value
// take_one: values[i] + dp[i + 1][1]
// take_two: values[i] + values[i + 1] + dp[i + 1][1]
// dp[i][0] = max(take_one, take_two)
// dp[i][1] = the remaining value after taking one or two
class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int n(values.size());
        vector<vector<int> > dp(n + 2, vector<int>(2));
        for (int i(n - 1); i >= 0; --i) {
            dp[i][0] = max(values[i] + dp[i + 1][1], values[i] + values[i + 1] + dp[i + 2][1]);
            dp[i][1] = min(dp[i + 1][0], dp[i + 2][0]);
        }
        return dp.front()[0] >= dp.front()[1];
    }
};
