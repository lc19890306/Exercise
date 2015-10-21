// DFS + backtracking solution - exponential time complexity
class Solution {
public:
    int totalNQueens(int n) {
        this->n = n;
        total = 0;
        only_col.resize(n, true);
        row_minus_col.resize((n << 1) - 1, true);
        row_plus_col.resize((n << 1) - 1, true);
        totalNQueens_helper(0);
        return total;
    }
    
private:
    void totalNQueens_helper(int row) {
        if (row == n) {
            ++total;
            return;
        }
        for (int col(0); col < n; ++col) {
            if (only_col[col] && row_minus_col[n - 1 + row - col] && row_plus_col[row + col]) {
                only_col[col] = row_minus_col[n - 1 + row - col] = row_plus_col[row + col] = false;
                totalNQueens_helper(row + 1);
                only_col[col] = row_minus_col[n - 1 + row - col] = row_plus_col[row + col] = true;
            }
        }
    }

    int total;
    int n;
    vector<bool> only_col;
    vector<bool> row_minus_col;
    vector<bool> row_plus_col;
};
