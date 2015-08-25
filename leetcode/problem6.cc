// 0, 1, 2, ..., numRows - 2, numRows - 1, numRows - 2, ..., 2, 1, 0, 1, 2, ...
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || numRows >= s.length())
            return s;
        vector<string> vec(numRows);
        int i(0);
        bool inc(true);
        for (auto &&c : s) {
            vec[i] += c;
            if (i == numRows - 1) inc = false;
            if (i == 0) inc = true;
            if (inc) ++i;
            else --i;
        }
        string ret;
        for (auto &&str : vec)
            ret += str;
        return ret;
    }
};
