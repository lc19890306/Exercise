// DP solution - O(n^3) time and O(n^2) space complexity
// dp[i][j]: whether the word concatenations constituting s[i:j] exist in the word dictionary
// if s[i:j] exists in the word dictionary, dp[i][j] is true
// or if both s[i:k] and s[k+1:j] exist in the word dictionary, dp[i][j] is true
// otherwise, dp[i][j] is false
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n(s.length());
        vector<vector<int> > dp(n, vector<int>(n));
        for (int i(0); i < n; ++i)
            for (int j(0); j + i < n; ++j) {
                if (wordDict.find(s.substr(j, i + 1)) != wordDict.end()) {
                    dp[j][j + i] = true;
                    continue;
                }
                for (int k(j); k < j + i; ++k) {
                    if (dp[j][k] && dp[k + 1][j + i]) {
                        dp[j][j + i] = true;
                        break;
                    }
                }
            }
        return dp.front().back();
    }
};

// Memorization DP solution - O(n^3) time and O(n^2) space complexity
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n(s.length());
        dp.resize(n, vector<int>(n, -1));
        return wordBreak(s, 0, n - 1, wordDict);
    }
    
private:
    bool wordBreak(string &s, int left, int right, unordered_set<string> &wordDict) {
        if (dp[left][right] != -1)
            return dp[left][right];
        for (int i(left); i < right; ++i)
            if (wordBreak(s, left, i, wordDict) && wordBreak(s, i + 1, right, wordDict)) {
                dp[left][right] = 1;
                return true;
            }
        dp[left][right] = wordDict.find(s.substr(left, right - left + 1)) != wordDict.end();
        return dp[left][right];
    }
    
    vector<vector<int> > dp;
};

// Optimized DP solution - O(n^2) time and O(n) space complexity
// dp[i]: whether a substring ending in s[i] exists in the word dictionary
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.empty() || wordDict.empty())
            return false;
        int n(s.length());
        vector<int> dp(n + 1);
        dp[0] = true;
        for (int i(1); i < dp.size(); ++i)
	  // go backwards and check substrings
            for (int j(i - 1); j >= 0; --j) {
                if (!dp[j])
                    continue;
                if (wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        return dp.back();
    }
};
