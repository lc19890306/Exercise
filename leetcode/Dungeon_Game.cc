// DP solution - O(m*n) time and space complexity
// dp[i][j]: the minimum number to keep alive from dungeon[i][j] (until dungeon[m - 1][n - 1])
// use bottom-up iteration because our target is to find the minimum number to keep alive in dungeon[0][0] and all the way until dungeon[m - 1][n - 1]
// so starting point should be dungeon[m - 1][n - 1]
// so check the below and the right and find the smaller between them, namely min(dp[i + 1][j], dp[i][j + 1])
// and then minus dungeon[i][j] to see the possible least hp to keep alive for the folowing way, namely min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]
// if the least hp calculated is less than 1, then we cannot use this hp because the knight will die in here so we have to use 1 instead to ensure he is alive from now on
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty() || dungeon.front().empty())
            return 1;
        int m(dungeon.size()), n(dungeon.front().size());
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m - 1][n] = 1;
        for (int i(m - 1); i >= 0; --i)
            for (int j(n - 1); j >= 0; --j)
                dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1);
        return dp.front().front();
    }
};

// Optimized DP solution - O(m*n) time and O(n) space complexity
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty() || dungeon.front().empty())
            return 1;
        int m(dungeon.size()), n(dungeon.front().size());
        vector<int> dp(n + 1, INT_MAX);
	// MUST be n - 1 rather than n because we have to ensure that in each row iteration, the last element (dp[n]) should be INT_MAX rather than 1!!!
        dp[n - 1] = 1;
        for (int i(m - 1); i >= 0; --i)
            for (int j(n - 1); j >= 0; --j)
                dp[j] = max(min(dp[j], dp[j + 1]) - dungeon[i][j], 1);
        return dp.front();
    }
};
