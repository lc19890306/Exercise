// DFS Backtracking solution
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty())
            return false;
        for (int row(0); row < board.size(); ++row) {
            for (int col(0); col < board[row].size(); ++col) {
                if (board[row][col] == word.front()) {
                    int key(row * board[row].size() + col);
                    hash_table.insert(key);
                    if (exist(board, row, col, word, 1))
                        return true;
                    hash_table.erase(key);
                }
            }
        }
        return false;
    }

private:
    bool exist(vector<vector<char> > &board, int row, int col, string word, int idx) {
        if (idx == word.length())
            return true;
        int key(row * board[row].size() + col);
        if (col > 0 && 
            hash_table.find(key - 1) == hash_table.end() &&
            board[row][col - 1] == word[idx]) {
            hash_table.insert(key - 1);
            if (exist(board, row, col - 1, word, idx + 1))
                return true;
            hash_table.erase(key - 1);
        }
        if (row > 0 &&
            hash_table.find(key - board[row].size()) == hash_table.end() &&
            board[row - 1][col] == word[idx]) {
            hash_table.insert(key - board[row].size());
            if (exist(board, row - 1, col, word, idx + 1))
                return true;
            hash_table.erase(key - board[row].size());
        }
        if (col < board[row].size() - 1 &&
            hash_table.find(key + 1) == hash_table.end() &&
            board[row][col + 1] == word[idx]) {
            hash_table.insert(key + 1);
            if (exist(board, row, col + 1, word, idx + 1))
                return true;
            hash_table.erase(key + 1);
        }
        if (row < board.size() - 1 &&
            hash_table.find(key + board[row].size()) == hash_table.end() &&
            board[row + 1][col] == word[idx]) {
            hash_table.insert(key + board[row].size());
            if (exist(board, row + 1, col, word, idx + 1))
                return true;
            hash_table.erase(key + board[row].size());
        }
        return false;
    }

    unordered_set<int> hash_table;
};

// Optimized solution
// use board to record visited cells
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty())
            return false;
        for (int row(0); row < board.size(); ++row) {
            for (int col(0); col < board[row].size(); ++col) {
                if (board[row][col] == word.front()) {
                    auto temp(board[row][col]);
		    // set visited
                    board[row][col] = 0;
                    if (exist(board, row, col, word, 1))
                        return true;
		    // reset not visited
                    board[row][col] = temp;
                }
            }
        }
        return false;
    }

private:
    bool exist(vector<vector<char> > &board, int row, int col, const string &word, int idx) {
        if (idx == word.length())
            return true;
        auto temp(word[idx]);
        if (col > 0 && 
            board[row][col - 1] == temp) {
            board[row][col - 1] = 0;
            if (exist(board, row, col - 1, word, idx + 1))
                return true;
            board[row][col - 1] = temp;
        }
        if (row > 0 &&
            board[row - 1][col] == temp) {
            board[row - 1][col] = 0;
            if (exist(board, row - 1, col, word, idx + 1))
                return true;
            board[row - 1][col] = temp;
        }
        if (col < board[row].size() - 1 &&
            board[row][col + 1] == temp) {
            board[row][col + 1] = 0;
            if (exist(board, row, col + 1, word, idx + 1))
                return true;
            board[row][col + 1] = temp;
        }
        if (row < board.size() - 1 &&
            board[row + 1][col] == temp) {
            board[row + 1][col] = 0;
            if (exist(board, row + 1, col, word, idx + 1))
                return true;
            board[row + 1][col] = temp;
        }
        return false;
    }
};
