// WRONG TLE DP solution
class Solution {
public:
    int minCut(string s) {
        if (s.empty())
            return 0;
        int n(s.length());
        vector<vector<int> > dp(n, vector<int>(n));
        for (int i(0); i < n; ++i)
            for (int j(0); j + i < n; ++j) {
                if (isPalindrome(s.substr(j, i + 1)))
                    continue;
                dp[j][j + i] = INT_MAX;
                for (int k(j); k < j + i; ++k)
                    dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i]);
                ++dp[j][j + i];
            }
        return dp.front().back();
    }
    
private:
    bool isPalindrome(const string &s) {
        if (s.empty())
            return false;
        for (int left(0), right(s.length() - 1); left < right; ++left, --right)
            if (s[left] != s[right])
                return false;
        return true;
    }
};

// DP solution - O(n^2) time and space complexity
// http://fisherlei.blogspot.com/2013/03/leetcode-palindrome-partitioning-ii.html
// dp[i]: the cut number of s[i:n-1]
// target: dp[0]
// dp[i] = min(1 + dp[j + 1]), means that s[i:j] is palindrome, and the cut number is min(1 + dp[j + 1]), where j is in range[i:n-1]
// to check whether s[i:j] is palindrome, use a matrix to record temporary results, namely isPalindrome[i:j] = s[i] == s[j] && (i+1 > j-1 || isPalindrome[i+1:j-1])
class Solution {
public:
    int minCut(string s) {
        if (s.empty())
            return 0;
        int n(s.length());
        vector<int> dp(n + 1);
	// initialize dp as the worst case: all adjacent letters should be cut, so "ab" is 1, "b" is 0
        for (int i(0); i <= n; ++i)
            dp[i] = n - i - 1;
        vector<vector<bool> > isPalindrome(n, vector<bool>(n));
        for (int i(n - 1); i >= 0; --i)
            for (int j(i); j < n; ++j)
                if (s[i] == s[j] && (j - i < 2 || isPalindrome[i + 1][j - 1])) {
                    isPalindrome[i][j] = true;
                    dp[i] = min(dp[i], dp[j + 1] + 1);
                }
        return dp.front();
    }
};

// Memorization recursive solution - Best for this problem
// ret[idx]: min cut number for s[idx:n-1]
// ret[idx] = min(1 + ret[i]), where i is in range from n to idx + 1 (backwards), because we need to calculate from the shortest to the longest, namely, s[n-1:n-1] to s[idx:n-1]
// 1 means that we need to check whether s[idx:i-1] is palindrome, if it is palindrome we add 1 to ret[i]
class Solution {
public:
    int minCut(string s) {
        if (s.empty())
            return 0;
        ret.resize(s.length() + 1, INT_MIN);
	// set last element as -1 because for the only element at last the min cut number should be -1 + 1 = 0
        ret.back() = -1;
        return minCut_helper(s, 0);
    }
    
private:
    bool isPalindrome(const string &s, int first, int last) {
        if (s.empty())
            return false;
        for (int left(first), right(last - 1); left < right; ++left, --right)
            if (s[left] != s[right])
                return false;
        return true;
    }
    
    int minCut_helper(const string &s, int idx) {
        if (ret[idx] != INT_MIN)
            return ret[idx];
        int n(s.length()), min_cut(INT_MAX);
        for (int i(n); i > idx; --i) {
            if (isPalindrome(s, idx, i))
                min_cut = min(min_cut, minCut_helper(s, i));
	    // if min_cut == 0, no need to keep searching for a smaller min_cut since min_cut cannot be less than 0
            if (min_cut < 1)
                break;
        }
        ret[idx] = min_cut + 1;
        return ret[idx];
    }
    
    vector<int> ret;
};
