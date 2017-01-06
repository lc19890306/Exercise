// BFS solution - O(n * 2^(n - 1)) time complexity
// Too slow
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ret;
        unordered_set<string> hash_table;
        queue<string> q;
        q.push(s);
        int valid_len(0);
        while (!q.empty()) {
            auto str(q.front());
            q.pop();
            if (str.length() < valid_len || hash_table.find(str) != hash_table.end())
                continue;
            hash_table.insert(str);
            if (isValid(str)) {
                ret.push_back(str);
                valid_len = str.length();
                continue;
            }
            for (int i(0); i < str.length(); ++i) {
                if (i > 0 && str[i] == str[i - 1] || str[i] != '(' && str[i] != ')')
                    continue;
                string key(str.substr(0, i) + str.substr(i + 1));
                q.push(key);
            }
        }
        return ret;
    }
    
private:
    bool isValid(const string &s) {
        int count(0);
        for (auto &&c: s)
            switch (c) {
                case '(': ++count; break;
                case ')':
                    if (--count < 0)
                        return false;
                default:
                    break;
            }
        return !count;
    }
};

// Use this solution
// DFS + backtracking solution
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
      // preprocessing - obtain the number of opening and closing parentheses to be removed
      // after preprocessing, we can know the maximum depth of DFS
        int left_removed(0), right_removed(0);
        for (auto &&c : s)
            switch (c) {
                case '(': ++left_removed; break;
                case ')': left_removed > 0 ? --left_removed : ++right_removed; break;
                default: break;
            }
        helper(s, 0, left_removed, right_removed);
        return ret;
    }
    
private:
    void helper(string s, int begin, int left_removed, int right_removed) {
      // if both a specified number of opening and closing parentheses have been removed
        if (!left_removed && !right_removed) {
            if (isValid(s))
                ret.push_back(s);
            return;
        }
        for (int i(begin); i < s.length(); ++i) {
	  // avoid unnecessary removing due to consecutive opening or closing parentheses
            if (i > begin && s[i - 1] == s[i])
                continue;
            if (s[i] == '(' && left_removed > 0)
	      // BE CAREFUL!!! s.substr(0, i) rather than s.substr(begin, i) !!!!!!
                helper(s.substr(0, i) + s.substr(i + 1), i, left_removed - 1, right_removed);
            else if (s[i] == ')' && right_removed > 0)
                helper(s.substr(0, i) + s.substr(i + 1), i, left_removed, right_removed - 1);
        }
    }
    
    bool isValid(string s) {
        int count(0);
        for (auto &&c: s)
            switch (c) {
                case '(': ++count; break;
                case ')':
		  // opening and closing parentheses should be paired
		  // if count < 0, there must be a redundant closing parenthesis, return false directly
                    if (--count < 0)
                        return false;
                default:
                    break;
            }
	// if count > 0, there must be some redundant opening parentheses
        return !count;
    }
    
    vector<string> ret;
};
