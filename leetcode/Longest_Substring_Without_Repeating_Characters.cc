class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash_map;
        int ret(0), l(0), r(0);
        for (; r < s.length(); ++r) {
            if (hash_map.find(s[r]) == hash_map.end() || hash_map[s[r]] < l)
                hash_map[s[r]] = r;
            else {
                ret = max(ret, r - l);
                l = hash_map[s[r]] + 1;
                hash_map[s[r]] = r;
            }
        }
        return max(ret, r - l);
    }
};

// ascii code table has 256 characters, using a vector with a length of 256 to store character frequency is faster than using hashmap
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash_map(256, -1);
        int ret(0), l(0), r(0);
        for (; r < s.length(); ++r) {
            if (hash_map[s[r]] == -1 || hash_map[s[r]] < l)
                hash_map[s[r]] = r;
            else {
                ret = max(ret, r - l);
                l = hash_map[s[r]] + 1;
                hash_map[s[r]] = r;
            }
        }
        return max(ret, r - l);
    }
};

// Assume s[l:r] is currently the longest target substring
// if s[r + 1] exists in s[l:r]
// l = hash_map[s[r]] + 1 if hash_map[s[r]] >= l, namely, the position of previous s[r] is in between [l:r] and will affect s[l:r], therefore update l
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash_map(256, -1);
        int ret(0), l(0);
        for (int r(0); r < s.length(); ++r) {
            l = max(hash_map[s[r]] + 1, l);
            hash_map[s[r]] = r;
            ret = max(ret, r - l + 1);
        }
        return ret;
    }
};
