// Awesome solution!!! - O(m + n) time complexity
// always starts from the top right corner
// 1. if the top right element is less than target, rule out corresponding row since the top right element, the largest element in this row, is less than target
// 2. if the top right element is greater than target, rule out corresponding column since the top right element, the smallest element in this column, is greater than target
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix.front().empty())
            return false;
        int m(matrix.size()), n(matrix.front().size());
        for (int row(0), col(n - 1); row < m && col >= 0;) {
            if (matrix[row][col] < target)
                ++row;
            else if (matrix[row][col] > target)
                --col;
            else
                return true;
        }
        return false;
    }
};
