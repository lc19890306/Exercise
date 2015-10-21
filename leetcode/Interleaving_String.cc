// DP solution - O(m*n) time and space complexity
// s[i]: the (i + 1)-th character in s
// matched[i][j]: whether s3[0 : i + j - 1] is the interleaving of s1[0 : i - 1] and s2[0 : j - 1]
// if s1[i - 1] == s3[i + j - 1] AND matched[i - 1][j] OR
// s2[j - 1] == s3[i + j - 1] AND matched[i][j - 1]
// matched[i][j] = true;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length())
            return false;
        vector<vector<bool> > matched(s1.length() + 1, vector<bool>(s2.length() + 1));
        matched[0][0] = true;
        for (int i1(1); i1 < matched.size(); ++i1)
            if (s1[i1 - 1] == s3[i1 - 1])
                matched[i1][0] = true;
            else
                break;
        for (int i2(1); i2 < matched.front().size(); ++i2)
            if (s2[i2 - 1] == s3[i2 - 1])
                matched[0][i2] = true;
            else
                break;
        for (int i1(1); i1 < matched.size(); ++i1) {
            for (int i2(1); i2 < matched[i1].size(); ++i2)
                matched[i1][i2] = (s1[i1 - 1] == s3[i1 + i2 - 1] && matched[i1 - 1][i2]) || (s2[i2 - 1] == s3[i1 + i2 - 1] && matched[i1][i2 - 1]);
        }
        return matched.back().back();
    }
};

// Optimized DP solution - O(m*n) time and O(n) space complexity
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m(s1.length()), n(s2.length());
        if (m + n != s3.length())
            return false;
        vector<bool> dp(n + 1);
        dp[0] = true;

        for (int i(1); i < dp.size(); ++i)
            if (s2[i - 1] == s3[i - 1])
                dp[i] = true;
            else
                break;
	// the same as the above code
        // for (int i(1); i < dp.size(); ++i)
	//   dp[i] = dp[i - 1] && s2[i - 1] == s3[i - 1];

        for (int i1(1); i1 <= m; ++i1) {
            dp[0] = dp[0] && s1[i1 - 1] == s3[i1 - 1];
            for (int i2(1); i2 <= n; ++i2) {
                dp[i2] = (dp[i2] && s1[i1 - 1] == s3[i1 + i2 - 1]) || (dp[i2 - 1] && s2[i2 - 1] == s3[i1 + i2 - 1]);
            }
        }
        return dp[n];
    }
};
