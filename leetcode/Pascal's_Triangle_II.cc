class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret(rowIndex + 1);
        ret[0] = 1;
        for (int row(1); row <= rowIndex; ++row) {
	  // add backwards for convenience
            for (int col(row - 1); col >= 0; --col)
                ret[col] += ret[col - 1];
            ret[row] = 1;
        }
        return ret;
    }
};
