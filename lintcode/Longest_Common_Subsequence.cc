// DP solution - O(m*n) time and space complexity
// dp[i][j]: LCS of A[0:i-1] and B[0:j-1]
// if A[i-1] == B[j-1], dp[i][j] = dp[i-1][j-1] + 1
// if A[i-1] != B[j-1], dp[i][j] = max{dp[i][j-1], dp[i-1][j]}
class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        vector<vector<int> > dp(A.length() + 1, vector<int>(B.length() + 1));
        for (int i(1); i < dp.size(); ++i)
            for (int j(1); j < dp[i].size(); ++j) {
                if (A[i - 1] == B[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        return dp.back().back();
    }
};
