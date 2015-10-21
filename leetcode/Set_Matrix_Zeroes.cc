// Brute-force solution - O(m * n) time and at worst O(m * n) space complexity
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int> > coordinates;
        for (int row(0); row < matrix.size(); ++row)
            for (int col(0); col < matrix[row].size(); ++col)
                if (!matrix[row][col])
                    coordinates.push_back(make_pair(row, col));
        for (auto &&coordinate : coordinates) {
            for (int row(0); row < matrix.size(); ++row)
                matrix[row][coordinate.second] = 0;
            for (int col(0); col < matrix[coordinate.first].size(); ++col)
                matrix[coordinate.first][col] = 0;
        }
    }
};

// O(m * n) time and O(1) space complexity
// use top row and left column to record if corresponding row and column should be set to 0
// for any element in the left column is 0, use extra col0 to record instead of set matrix[0][0] as 0, in order to avoid pollution
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix.front().empty())
            return;
        int m(matrix.size()), n(matrix.front().size()), col0(1);
        for (int row(0); row < m; ++row) {
            if (!matrix[row][0])
                col0 = 0;
            for (int col(1); col < n; ++col)
                if (!matrix[row][col])
                    matrix[row][0] = matrix[0][col] = 0;
        }
	// set zero bottom-up
	// if the first element in a row or column is 0, set corresponding row and column to 0
	// if col0 is 0, set the left column to 0
        for (int row(m - 1); row >= 0; --row) {
            for (int col(n - 1); col > 0; --col)
                if (!matrix[row][0] || !matrix[0][col])
                    matrix[row][col] = 0;
            if (!col0)
                matrix[row][0] = 0;
        }
    }
};
