// DP solution - O(m * n) time complexity
// DP[row][col]: the number of paths from DP[0][0] to DP[row][col]
// if DP[row][col] == 1, change it to 0, namely, no path to it
// if DP[0][0] != 1, set it to 1
// DP[0][col] = DP[0][col - 1]
// DP[row][0] = DP[row - 1][0]
// DP[row][col] = DP[row - 1][col] + DP[row][col - 1]
// class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        for (int row(0); row < obstacleGrid.size(); ++row)
            for (int col(0); col < obstacleGrid[row].size(); ++col) {
                if (obstacleGrid[row][col])
                    obstacleGrid[row][col] = 0;
                else if (!row && !col)
                    obstacleGrid[row][col] = 1;
                else if (!row)
                    obstacleGrid[row][col] = obstacleGrid[row][col - 1];
                else if (!col)
                    obstacleGrid[row][col] = obstacleGrid[row - 1][col];
                else
                    obstacleGrid[row][col] = obstacleGrid[row - 1][col] + obstacleGrid[row][col - 1];
            }
        return obstacleGrid.back().back();
    }
};

// Optimized DP solution
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int> > ret(obstacleGrid.size() + 1, vector<int>(obstacleGrid.front().size() + 1));
        ret[0][1] = 1;
        for (int row(1); row < ret.size(); ++row)
            for (int col(1); col < ret[row].size(); ++col)
                if (!obstacleGrid[row - 1][col - 1])
                    ret[row][col] = ret[row - 1][col] + ret[row][col - 1];
        return ret.back().back();
    }
};
