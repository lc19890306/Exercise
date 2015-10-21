// DP solution - O(m*n) time and space complexity
// dp[i][j]: length of common substring which MUST ends with A[i - 1] and B[j - 1], respectively
// if A[i - 1] != B[j - 1], dp[i][j] = 0
// otherwise dp[i][j] = dp[i - 1][j - 1] + 1
// update max length afterwards
class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        vector<vector<int> > dp(A.size() + 1, vector<int>(B.size() + 1));
        int ret(0);
        for (int i(1); i < dp.size(); ++i)
            for (int j(1); j < dp[i].size(); ++j)
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ret = max(ret, dp[i][j]);
                }
        return ret;
    }
};

