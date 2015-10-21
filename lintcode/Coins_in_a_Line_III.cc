// DP solution - O(n^2) time and space complexity
// dp[left:right]: the money two players taken for coins ranging in values[left:right]
// take_left = values[left] + dp[left+1:right].second
// take_right = values[right] + dp[left:right+1].second
// dp[left:right].first = max(take_left, take_right)
// dp[left:right].second = min(dp[left+1:right].first, dp[left:right+1].first)
class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int n(values.size());
        vector<vector<pair<int, int> > > dp(values.size(), vector<pair<int, int> >(n));
        for (int i(0); i < n; ++i)
            dp[i][i].first = values[i];
        for (int i(1); i < n; ++i)
            for (int j(0); j + i < n; ++j) {
                auto left(j), right(j + i);
                dp[left][right].first = max(values[left] + dp[left + 1][right].second, values[right] + dp[left][right - 1].second);
                dp[left][right].second = min(dp[left + 1][right].first, dp[left][right - 1].first);
            }
        return dp.front().back().first >= dp.front().back().second;
    }
};
