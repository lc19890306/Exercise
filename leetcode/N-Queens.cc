// DFS + Backtracking solution - exponential time complexity
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        chessboard.resize(n, string(n, '.'));
        solveNQueens(0, 0);
        return ret;
    }

private:
    void solveNQueens(int row, int col) {
        if (row == n) {
            ret.push_back(chessboard);
            return;
        }
        for (int i(0); i < n; ++i) {
            auto temp((col + i) % n);
            if (only_col[temp] == 0
                && row_minus_col[row - temp] == 0
                && row_plus_col[row + temp] == 0) {
                ++only_col[temp];
                ++row_minus_col[row - temp];
                ++row_plus_col[row + temp];
                chessboard[row][temp] = 'Q';
                solveNQueens(row + 1, (col + i + 2) % n);
                chessboard[row][temp] = '.';
                --only_col[temp];
                --row_minus_col[row - temp];
                --row_plus_col[row + temp];
            }
        }
    }
    
    int n;
    unordered_map<int, int> only_col;
    unordered_map<int, int> row_minus_col;
    unordered_map<int, int> row_plus_col;
    vector<string> chessboard;
    vector<vector<string> > ret;
};

// use boolean vector instead of hashmap
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        chessboard.resize(n, string(n, '.'));
        only_col.resize(n, false);
        row_minus_col.resize((n << 1) - 1, false);
        row_plus_col.resize((n << 1) - 1, false);
        solveNQueens_helper(0);
        return ret;
    }

private:
    void solveNQueens_helper(int row) {
        if (row == n) {
            ret.push_back(chessboard);
            return;
        }
        for (int col(0); col < n; ++col) {
            if (!only_col[col]
                && !row_minus_col[n - 1 + row - col]
                && !row_plus_col[row + col]) {
                only_col[col] = row_minus_col[n - 1 + row - col] = row_plus_col[row + col] = true;
                chessboard[row][col] = 'Q';
                solveNQueens_helper(row + 1);
                chessboard[row][col] = '.';
                only_col[col] = row_minus_col[n - 1 + row - col] = row_plus_col[row + col] = false;
            }
        }
    }
    
    int n;
    vector<bool> only_col;
    vector<bool> row_minus_col;
    vector<bool> row_plus_col;
    vector<string> chessboard;
    vector<vector<string> > ret;
};
