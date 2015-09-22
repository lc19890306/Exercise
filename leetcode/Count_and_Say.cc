// Static vector solution - amortized O(1) time complexity if randomly call it for multiple times, otherwise O(n) time complexity
// O(n) space complexity
class Solution {
public:
    string countAndSay(int n) {
        static vector<string> strs;
        int prev_size(strs.size());
        if (n > prev_size)
            strs.resize(n);
        else
            return strs[n - 1];
        if (strs[0].empty())
            strs[0] = "1";
        for (int i(max(1, prev_size)); i < n; ++i) {
            int j(0);
            while (j < strs[i - 1].size()) {
                int counter(1);
                while (++j < strs[i - 1].size() && strs[i - 1][j] == strs[i - 1][j - 1])
                    ++counter;
                strs[i] += ('0' + counter);
                strs[i] += strs[i - 1][j - 1];
            }
        }
        return strs[n - 1];
    }
};

// Regular solution - O(n) time complexity and O(1) space complexity
class Solution {
public:
    string countAndSay(int n) {
        if (n < 1)
            return "";
        string num("1");
        while (--n > 0)
            num = say(num);
        return num;
    }
    
private:
    string say(string s) {
        string ret;
        int i(0);
        while (i < s.size()) {
            int counter(1);
            while (++i < s.size() && s[i] == s[i - 1])
                ++counter;
            ret += ('0' + counter);
            ret += s[i - 1];
        }
        return ret;
    }
};
