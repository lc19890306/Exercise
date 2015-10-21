// O(n^2) time and space complexity
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int> > h(9), v(9), s(9);
        for (int row(0); row < 9; ++row)
            for (int col(0); col < 9; ++col) {
                if (board[row][col] == '.')
                    continue;
                auto num(board[row][col] - '0');
                if (h[row].find(num) == h[row].end())
                    h[row].insert(num);
                else
                    return false;
                if (v[col].find(num) == v[col].end())
                    v[col].insert(num);
                else
                    return false;
                if (s[row / 3 * 3 + col / 3].find(num) == s[row / 3 * 3 + col / 3].end())
                    s[row / 3 * 3 + col / 3].insert(num);
                else
                    return false;
            }
        return true;
    }
};

// bitset solution - fastest
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bitset<9> > h(9), v(9), s(9);
        for (int row(0); row < 9; ++row)
            for (int col(0); col < 9; ++col) {
                if (board[row][col] == '.')
                    continue;
                auto num(board[row][col] - '1');
                if (!h[row][num] && !v[col][num] && !s[row / 3 * 3 + col / 3][num])
                    h[row][num] = v[col][num] = s[row / 3 * 3 + col / 3][num] = true;
                else
                    return false;
            }
        return true;
    }
};
