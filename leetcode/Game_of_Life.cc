// O(mn) time complexity
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board.front().empty())
            return;
        vector<pair<int, int> > neighbors{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        for (int row(0); row < board.size(); ++row)
            for (int col(0); col < board[row].size(); ++col) {
                int live_count(0);
                for (auto &&neighbor : neighbors) {
                    auto n_row(row + neighbor.first), n_col(col + neighbor.second);
                    if (0 <= n_row && n_row < board.size() &&
                        0 <= n_col && n_col < board[row].size()) {
                        if (board[n_row][n_col] > 0)
                            ++live_count;
			// restore the upperleft neighbor
                        if (neighbor == make_pair(-1, -1) ||
			    // restore the upper neighbor when reaches the right border
                            neighbor == make_pair(-1, 0) && col + 1 == board[row].size() ||
			    // restore the left neighbor when reaches the bottom border
                            neighbor == make_pair(0, -1) && row + 1 == board.size())
			  // -1 means originally 0 now should be 1
                            if (board[n_row][n_col] == -1)
                                board[n_row][n_col] = 1;
			// 2 means originally 1 now should be 0
                            else if (board[n_row][n_col] == 2)
                                board[n_row][n_col] = 0;
                    }
                }
                if (board[row][col]) {
                    if (live_count < 2 || live_count > 3)
                        board[row][col] = 2;
                }
                else
                    if (live_count == 3)
                        board[row][col] = -1;
            }
	// restore the last one on the board
        if (board.back().back() == -1)
            board.back().back() = 1;
        else if (board.back().back() == 2)
            board.back().back() = 0;
    }
};

// Best solution for this problem
// Since each cell on board is 0 or 1, use the high bit to represent the new state
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m(board.size()), n(m ? board.front().size() : 0);
        for (int row(0); row < m; ++row)
            for (int col(0); col < n; ++col) {
	      // count all live neighbor cells including the cell itself
                int live_count(0);
                for (int i(max(row - 1, 0)); i < min(row + 2, m); ++i)
                    for (int j(max(col - 1, 0)); j < min(col + 2, n); ++j)
                        live_count += (board[i][j] & 1);
		// the new state is live only if
		// 1. the cell itself is live and the number of live neighbors is 2 (summation is 3)
		// 2. the cell itself is live and the number of live neighbors is 3 (total number is 4 and the difference is 4 - 1 = 3)
		// 3. the cell itself is dead and the number of live neighbors is 3 (total number is 3)
		// case 1 and 3 can be combined as total count is 3
                if (live_count == 3 || live_count - board[row][col] == 3)
		  // set the high bit as 1
                    board[row][col] |= 2;
            }
	// right shift each cell 1 bit to get the new state
        for (int row(0); row < m; ++row)
            for (int col(0); col < n; ++col)
                board[row][col] >>= 1;
    }
};

// For follow up 2
// represent the board as a set of live cell coordinates
