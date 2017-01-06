class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for (auto &&c : s)
            if (isalnum(c)) {
	      // if c is upper-case
                if (isalpha(c) && c < 'a')
                    str += ('a' + c - 'A');
                else
                    str += c;
            }
        auto temp(str);
        reverse(str.begin(), str.end());
        return temp == str;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for (auto &&c : s)
            if (isalnum(c)) {
                if (isalpha(c) && c < 'a')
                    str += ('a' + c - 'A');
                else
                    str += c;
            }
        for (int i(0), j(str.length() - 1); i <= j; ++i, --j)
            if (str[i] != str[j])
                return false;
        return true;
    }
};

// Best solution
class Solution {
public:
    bool isPalindrome(string s) {
        for (int l(0), r(s.length() - 1); l < r; ++l, --r) {
            while (l < r && !isalnum(s[l]))
                ++l;
            while (l < r && !isalnum(s[r]))
                --r;
            if (toupper(s[l]) != toupper(s[r]))
                return false;
        }
        return true;
    }
};
