// DP solution - O(m * n) time and O(m) space complexity
// Classical knapsack (backpack) problem
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        vector<int> dp(m + 1);
        for (int i(0); i < A.size(); ++i)
            for (int j(m); j > 0; --j)
                dp[j] = A[i] > j ? dp[j] : max(dp[j], V[i] + dp[j - A[i]]);
        return dp.back();
    }
};
