// O(2^n) time and O(1) space complexity (excluding final result)
// example: n = 3
// ret[0]: 000
// ret[1]: 000 + (1 << 0) = 001
// ret[2]: 001 + (1 << 1) = 011
// ret[3]: 000 + (1 << 1) = 010
// ret[4]: 010 + (1 << 2) = 110
// ret[5]: 011 + (1 << 2) = 111
// ret[6]: 001 + (1 << 2) = 101
// ret[7]: 000 + (1 << 2) = 100
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret(1);
        for (int i(0); i < n; ++i) {
            int size(ret.size());
            for (int j(size - 1); j >= 0; --j) {
                ret.push_back(ret[j]);
                ret.back() += (1 << i);
            }
        }
        return ret;
    }
};
