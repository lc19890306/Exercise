class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        if (haystack.length() < needle.length())
            return -1;
        int i(-1);
        int diff(haystack.length() - needle.length());
        while (i < diff) {
            while (++i < diff && needle[0] != haystack[i]);
            if (same(needle, haystack, i))
                return i;
        }
        return -1;
    }
    
private:
    bool same(string needle, string haystack, int i) {
        for (int j(0); j < needle.length(); ++j)
            if (needle[j] != haystack[i + j])
                return false;
        return true;
    }
};

// Use STL string::substr
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        if (haystack.length() < needle.length())
            return -1;
        int i(-1);
        int diff(haystack.length() - needle.length());
        while (i < diff) {
            while (++i < diff && needle[0] != haystack[i]);
            if (haystack.substr(i, needle.length()) == needle)
                return i;
        }
        return -1;
    }
};
