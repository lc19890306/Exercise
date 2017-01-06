// O(n^2) time complexity
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ret;
        if (!numRows)
            return ret;
        ret.push_back({1});
        for (int row(1); row < numRows; ++row) {
            vector<int> vec;
            vec.push_back(1);
            for (int col(1); col < row; ++col)
                vec.push_back(ret[row - 1][col - 1] + ret[row - 1][col]);
            vec.push_back(1);
            ret.push_back(vec);
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ret(numRows);
        if (numRows < 1)
            return ret;
        ret[0].push_back(1);
        for (int i(1); i < numRows; ++i) {
            ret[i].resize(i + 1, 1);
            for (int j(1); j < i; ++j)
                ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
        }
        return ret;
    }
};
