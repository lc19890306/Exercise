// O(nlogn)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// O(n) on average
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> char_freq;
        for (auto &&c : s)
            ++char_freq[c];
        for (auto &&c : t)
            --char_freq[c];
        for (auto &&pair : char_freq)
            if (pair.second != 0)
                return false;
        return true;
    }
};

// Best performance - worst case O(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        int char_freq[26] = {0};
        for (auto &&c : s)
            ++char_freq[c - 'a'];
        for (auto &&c : t)
            --char_freq[c - 'a'];
        for (auto i(0); i != 26; ++i)
            if (char_freq[i])
                return false;
        return true;
    }
};
