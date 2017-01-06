// DP solution - O(m * n) time and space complexity at worst
//   rabbbit
//  11111111
// r01111111
// a00111111
// b00012333
// b00001333
// i00000033
// t00000003
// dp[i][j]: number of distinct subsequences of t[1:i-1] in s[1:j-1]
// if t[i - 1] == s[j - 1], dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1], namely, t[i - 1] can pair with s[j - 1] for dp[i - 1][j - 1] or pair with any other previous char in s[1:j-2] for dp[i][j - 1]
// otherwise, dp[i][j] = dp[i][j - 1], namely, either t[i - 1] pairs with a previous char in s[1:j-2] or a later char in s[j:n-1], so dp[i][j] should be the same as dp[i][j - 1]
class Solution {
public:
    int numDistinct(string s, string t) {
        int m(t.length()), n(s.length());
        if (m > n)
            return 0;
        vector<vector<int> > dp(m + 1, vector<int>(n + 1));
        fill(dp.front().begin(), dp.front().end(), 1);
        for (int i(1); i <= m; ++i) {
            for (int j(i); j <= n; ++j)
                dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
            if (!dp[i].back())
                return 0;
        }
        return dp.back().back();
    }
};

// Optimized DP solution - O(m * n) time and O(m) space complexity
class Solution {
public:
    int numDistinct(string s, string t) {
        int m(t.length()), n(s.length());
        if (m > n)
            return 0;
        vector<int> dp(m + 1);
        dp[0] = 1;
        for (int j(1); j <= n; ++j)
            for (int i(m); i > 0; --i)
                dp[i] += t[i - 1] == s[j - 1] ? dp[i - 1] : 0;
        return dp.back();
    }
};
