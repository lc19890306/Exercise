class Solution {
public:
    int titleToNumber(string s) {
        int ret(0);
        if (s.empty())
            return 0;
        for (auto &&c : s)
            ret = ret * 26 + c - '@';
        return ret;
    }
};
