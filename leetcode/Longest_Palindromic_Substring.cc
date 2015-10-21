class Solution {
public:
    string longestPalindrome(string s) {
        string ret;
        for (int i(0); i < s.length(); ++i) {
            int j;
            for (j = 0; j <= i && i + j < s.length() && s[i - j] == s[i + j]; ++j);
            if (ret.length() < (j << 1) - 1)
                ret = s.substr(i - j + 1, (j << 1) - 1);
            for (j = 0; j + 1 <= i && i + j < s.length() && s[i - j - 1] == s[i + j]; ++j);
            if (ret.length() < (j << 1))
                ret = s.substr(i - j, (j << 1));
        }
        return ret;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int l(0), r(-1);
        for (int i(0); i < s.length(); ++i) {
            int j;
            for (j = 0; j <= i && i + j < s.length() && s[i - j] == s[i + j]; ++j);
            if (r - l + 1 < (j << 1) - 1) {
                l = i - j + 1;
                r = i + j - 1;
            }
            for (j = 0; j + 1 <= i && i + j < s.length() && s[i - j - 1] == s[i + j]; ++j);
            if (r - l + 1 < (j << 1)) {
                l = i - j;
                r = i + j - 1;
            }
        }
        return s.substr(l, r - l + 1);
    }
};

// O(n^2)
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.length() < 2)
            return s;
        int longest_l(0), longest_len(1), l, r;
	// i is the center of the mirror
	// s.length() - i > (longest_len >> 1) requires the number of remaining elements should be larger than high the size of current longest length otherwise there is no need to go ahead
        for (int i(0); i < s.length() && s.length() - i > (longest_len >> 1);) {
            l = r = i;
	    // find the first different element to avoid odd and even number checking
            while (r < s.length() - 1 && s[r] == s[r + 1]) ++r;
            i = r + 1;
            while (l > 0 && r < s.length() - 1 && s[l - 1] == s[r + 1]) {
                --l;
                ++r;
            }
            if (longest_len < r - l + 1) {
                longest_l = l;
                longest_len = r - l + 1;
            }
        }
        return s.substr(longest_l, longest_len);
    }
};

// O(n) solution is possible but too difficult
