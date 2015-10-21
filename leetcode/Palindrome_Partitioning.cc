// Backtracking + memorization solution - exponential at worst
// worst case: "abcdefg"
// IGNORE IT!!!
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        int n(s.length());
        for (int i(n - 1); i >= 0; --i) {
            auto key(s.substr(i));
            if (isPalindrome(key)) {
                for (auto &&p : partition(s.substr(0, i))) {
                    ret.push_back(p);
                    ret.back().push_back(key);
                }
                if (!i)
                    ret.push_back({key});
            }
        }
        return ret;
    }
    
private:
    bool isPalindrome(const string &s) {
        if (s.empty())
            return false;
        if (hash_table.find(s) != hash_table.end())
            return true;
        for (int left(0), right(s.length() - 1); left < right; ++left, --right)
            if (s[left] != s[right])
                return false;
        hash_table.insert(s);
        return true;
    }

    unordered_set<string> hash_table;
};

// Backtracking solution - exponential at worst
// Best for this problem
class Solution {
public:
    vector<vector<string>> partition(string s) {
        partition_helper(s);
        return ret;
    }
    
private:
    bool isPalindrome(const string &s) {
        for (int left(0), right(s.length() - 1); left < right; ++left, --right)
            if (s[left] != s[right])
                return false;
        return true;
    }

    void partition_helper(const string &s) {
        if (s.empty()) {
            ret.push_back(str);
            return;
        }
        int n(s.length());
        for (int i(1); i <= n; ++i) {
            auto key(s.substr(0, i));
            if (isPalindrome(key)) {
                str.push_back(key);
                partition_helper(s.substr(i));
                str.pop_back();
            }
        }
    }

    vector<string> str;
    vector<vector<string> > ret;
};
