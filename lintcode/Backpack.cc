// DP solution - O(m*n) time and space complexity
// dp[i][j]: maximum size in a backpack with a size of j after checking i items
// if item[i] is greater than current backpack size j, item[i] will not be put into the backpack and therefore the maximum size is still the same as that after checking (i - 1) items, namely, dp[i][j] = dp[i - 1][j]
// if item[i] is not greater than current backpack size j, compare the two cases
// (1) put item[i] into the backpack, the remaining space is j - item[i], the maximum size is the summation of item[i] and the maximum size in a backpack with a size of the remaining size (j - item[i]) after checking item[i - 1], namely, dp[i - 1][j - item[i]]
// (2) not put item[i] into the backpack, the maximum size remains the same as that after checking (i - 1) items, namely, dp[i][j] = dp[i - 1][j]
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        vector<vector<int> > dp(A.size() + 1, vector<int>(m + 1));
        int ret(0);
        for (int i(1); i < dp.size(); ++i)
            for (int j(1); j <= m; ++j)
                dp[i][j] = A[i - 1] > j ? dp[i - 1][j] : max(dp[i - 1][j], A[i - 1] + dp[i - 1][j - A[i - 1]]);
        return dp.back().back();
    }
};

// Optimized DP solution - O(m *n) time and O(m) space complexity
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        vector<int> dp(m + 1);
        for (auto &&item : A)
	  // since each time we need to check the previous row and col, use backwards iteration
            for (int i(m); i > 0; --i)
                dp[i] = item > i ? dp[i] : max(dp[i], item + dp[i - item]);
        return dp.back();
    }
};
