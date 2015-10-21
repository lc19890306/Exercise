class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row(0), col(0);
        for (; row < matrix.size(); ++row)
            if (matrix[row][0] > target)
                break;
        --row;
        if (row < 0)
            return false;
        for (; col < matrix[row].size(); ++col)
            if (matrix[row][col] > target)
                break;
        return matrix[row][col - 1] == target;
    }
};

// General solution - O(m + n) time complexity
// Easy to popularize
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

// Binary search solution - O(log(m * n)) time complexity
// Treat the entire matrix as a sorted array, use binary search
// Best solution in theory
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix.front().empty())
            return false;
        int m(matrix.size()), n(matrix.front().size()), left(0), right(m * n - 1);
        while (left <= right) {
            auto mid((left + right) >> 1);
            int row(mid / n), col(mid % n);
            if (matrix[row][col] < target)
                ++left;
            else if (matrix[row][col] > target)
                --right;
            else
                return true;
        }
        return false;
    }
};
