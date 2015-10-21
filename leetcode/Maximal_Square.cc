// DP solution - O(m*n) time and space complexity
// dp[i][j]: maximum length of square, the bottom right corner is matrix[i - 1][j - 1]
// if matrix[i - 1][j - 1] == 0, dp[i][j] = 0
// otherwise, dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix.front().empty())
            return 0;
        int m(matrix.size()), n(matrix.front().size());
        int max_length(0);
        vector<vector<int> > dp(m + 1, vector<int>(n + 1));
        for (int i(1); i < dp.size(); ++i)
            for (int j(1); j < dp[i].size(); ++j) {
                dp[i][j] = matrix[i - 1][j - 1] == '1' ? min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1 : 0;
                max_length = max(max_length, dp[i][j]);
            }
        return max_length * max_length;
    }
};

// Optimized DP solution - O(m*n) time and O(n) space complexity
// dp[i - 1][j - 1] dp[i - 1][j]     dp[j - 1] dp[j]
// dp[i][j - 1]     dp[i][j]     ==> pre       dp[j]
// dp[j] = min(dp[j - 1], dp[j], pre)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix.front().empty())
            return 0;
        int m(matrix.size()), n(matrix.front().size());
        int max_length(0), pre(0);
        vector<int> dp(n + 1);
        for (int i(0); i < m; ++i) {
            for (int j(1); j < dp.size(); ++j) {
                auto temp(dp[j]);
                dp[j] = matrix[i][j - 1] == '1' ? min(dp[j], min(dp[j - 1], pre)) + 1 : 0;
                max_length = max(max_length, dp[j]);
                pre = temp;
            }
        }
        return max_length * max_length;
    }
};

// O(m*n*m) time and O(n) space complexity
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix.front().empty())
            return 0;
        int m(matrix.size()), n(matrix.front().size());
        int max_length(0);
        vector<int> height(n);
        for (int row(0); row < m; ++row) {
            for (int col(0); col < n; ++col)
                height[col] = matrix[row][col] == '1' ? height[col] + 1 : 0;
            for (int len(row + 1); len > max_length; --len) {
                int count(0);
                bool changed(false);
                for (int col(0); col < n; ++col) {
                    count = height[col] >= len ? count + 1 : 0;
                    if (count >= len) {
                        max_length = max(max_length, len);
                        changed = true;
                        break;
                    }
                }
                if (changed)
                    break;
            }
        }
        return max_length * max_length;
    }
};
