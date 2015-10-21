// DP solution - O(A.size() * (max(A) - min(A)) * target) time and O(A.size() * (max(A) - min(A)) space complexity
// this is actually a variant of knapsack (backpack) problem
// since each element in the final result should in the [min(A), max(A)] (for this problem, this range can be simplified as [1, 100]), we assume that each element can be adjusted to the element in the range
// dp[i][j]: minimum adjustment cost summation after checking i numbers in A and the i-th number is adjusted to j or range[j]
// for each dp[i][j], we find the minimum adjustment cost summation after checking (i - 1) numbers in A in the range [max(0, j - target), min(range_size, j + target + 1)), and then add the difference between the i-th number in A and j, namely, |A[i - 1] - j (or range[j])|
class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
        auto min_max(minmax_element(A.begin(), A.end()));
        auto smallest(*min_max.first), largest(*min_max.second);
        vector<int> range(largest - smallest + 1);
        iota(range.begin(), range.end(), smallest);
        vector<vector<int> > dp(A.size() + 1, vector<int>(range.size()));
        for (int i(1); i < dp.size(); ++i)
            for (int j(0); j < dp[i].size(); ++j)
                dp[i][j] = *min_element(dp[i - 1].begin() + max(0, j - target), dp[i - 1].begin() + min((int)dp[i - 1].size(), j + target + 1)) + abs(A[i - 1] - range[j]);
	// at last, find the minimum adjustment cost summation after checking the last element in A
        return *min_element(dp.back().begin(), dp.back().end());
    }
};

// DP solution for this problem, almost the same
class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
        vector<vector<int> > dp(A.size() + 1, vector<int>(101));
        for (int i(1); i < dp.size(); ++i)
            for (int j(1); j < 101; ++j)
                dp[i][j] = *min_element(dp[i - 1].begin() + max(1, j - target), dp[i - 1].begin() + min(101, j + target + 1)) + abs(A[i - 1] - j);
        return *min_element(dp.back().begin() + 1, dp.back().end());
    }
};
