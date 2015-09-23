// Recursive solution - O(n) time complexity
// To ensure valid sequence:
// 1. if the number of ")" is 0, only append "("
// 2. otherwise, either "(" or ")" can be appended
// 
// TO CONTROL THE NUMBER OF ")":
// 1. each time a "(" is appended, decrement the number of "(" and increment the number of ")"
// 2. each time a ")" is appended, just decrement the number of ")"
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        generateParenthesis(ret, "", n, 0);
        return ret;
    }
    
private:
    void generateParenthesis(vector<string> &ret, string str, int left, int right) {
        if (!left && !right)
            ret.push_back(str);
        if (left > 0)
            generateParenthesis(ret, str + "(", left - 1, right + 1);
        if (right > 0)
            generateParenthesis(ret, str + ")", left, right - 1);
    }
};

// DP solution - O(n) time complexity and O(n^2) space complexity??
// ret[0] = ""
// ret[1] = "(ret[0])"
// ret[2] = "(ret[0])ret[1]", "(ret[1])"
// ret[3] = "(ret[0])ret[2]", "(ret[1])ret[1]", "(ret[2])"
// ret[n] = "(ret[0])ret[n - 1]", "(ret[1])ret[n - 2]", ..., "(ret[n - 2])ret[1]", "(ret[n - 1])ret[0]"
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string> > ret(n + 1);
        ret[0].push_back("");
        for (int i(1); i <= n; ++i) {
            vector<string> vec;
            for (int j(0); j < n; ++j) {
                for (auto &&first : ret[j]) {
                    for (auto &&second : ret[i - j - 1])
                        vec.push_back("(" + first + ")" + second);
                }
            }
            ret[i]= vec;
        }
        return ret[n];
    }
};
