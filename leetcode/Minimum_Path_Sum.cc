class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m(grid.size()), n(grid[0].size());
        for (int i(1); i != n; ++i)
            grid[0][i] += grid[0][i - 1];
        for (int i(1); i != m; ++i)
            grid[i][0] += grid[i - 1][0];
        for (int i(2); i < m + n - 1; ++i)
            for (int row(max(i - n + 1, 1)); row < min(i, m); ++row) {
                auto col(i - row);
                grid[row][col] += min(grid[row - 1][col], grid[row][col - 1]);
            }
        return grid[m - 1][n - 1];
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m(grid.size()), n(grid[0].size());
        for (int col(1); col != n; ++col)
            grid[0][col] += grid[0][col - 1];
        for (int row(1); row != m; ++row) {
            grid[row][0] += grid[row - 1][0];
            for (int col(1); col != n; ++col)
                grid[row][col] += min(grid[row - 1][col], grid[row][col - 1]);
        }
        return grid[m - 1][n - 1];
    }
};
