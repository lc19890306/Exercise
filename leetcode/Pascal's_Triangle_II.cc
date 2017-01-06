class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret(rowIndex + 1, 1);
        for (int i(2); i < ret.size(); ++i) {
	  // add backwards for convenience
            for (int j(i - 1); j > 0; --j)
                ret[j] += ret[j - 1];
        }
        return ret;
    }
};
