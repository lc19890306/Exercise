class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return;
        int n(matrix.size() >> 1);
        for (int row(0); row < n; ++row)
            for (int col(row); col < matrix.size() - 1 - row; ++col) {
                auto temp(matrix[row][col]);
                matrix[row][col] = matrix[matrix.size() - 1 - col][row];
                matrix[matrix.size() - 1 - col][row] = matrix[matrix.size() - 1 - row][matrix.size() - 1 - col];
                matrix[matrix.size() - 1 - row][matrix.size() - 1 - col] = matrix[col][matrix.size() - 1 - row];
                matrix[col][matrix.size() - 1 - row] = temp;
            }
    }
};

// Best solution!!!
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      // reverse upside down
      // 1 2 3    7 8 9
      // 4 5 6 => 4 5 6
      // 7 8 9    1 2 3
        reverse(matrix.begin(), matrix.end());
	// spin around the diagonal
	// 7 8 9    7 4 1
	// 4 5 6 => 8 5 2
	// 1 2 3    9 6 3
        for (int i(0); i < matrix.size() - 1; ++i)
            for (int j(i + 1); j < matrix.size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
};

// auti-clockwise rotate
void anti_rotate(vector<vector<int> > &matrix) {
    for (auto &&vi : matrix)
      reverse(vi.begin(), vi.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}
