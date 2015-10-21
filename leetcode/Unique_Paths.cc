// DP solution - O(m * n) time complexity
// ret[row][col]: the number of unique paths from ret[0][0] to ret[row][col]
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > ret(m, vector<int>(n, 1));
        for (int row(1); row < m; ++row)
            for (int col(1); col < n; ++col)
                ret[row][col] = ret[row - 1][col] + ret[row][col - 1];
        return ret[m - 1][n - 1];
    }
};
