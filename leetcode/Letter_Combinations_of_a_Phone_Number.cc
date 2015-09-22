const vector<vector<string> > keyboards{{" "}, {}, {"a", "b", "c"}, {"d", "e", "f"}, {"g", "h", "i"}, {"j", "k", "l"},
                                  {"m", "n", "o"}, {"p", "q", "r", "s"}, {"t", "u", "v"}, {"w", "x", "y", "z"},
                                  {"+"}, {"#"}};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.empty())
            return ret;
        ret = keyboards[digits[0] - '0'];
        for (int i(1); i < digits.length(); ++i)
            ret = combine(ret, keyboards[digits[i] - '0']);
        return ret;
    }
    
private:
    vector<string> combine(const vector<string> &a, const vector<string> &b) {
        vector<string> ret;
        for (auto &&str_a : a)
            for (auto &&str_b : b)
                ret.push_back(str_a + str_b);
        return ret;
    }
};
