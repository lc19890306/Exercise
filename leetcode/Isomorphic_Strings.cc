class Solution {
public:
    bool isIsomorphic(string s, string t) {
      // unordered_map<char, int> hash_map_s, hash_map_t;
        int hash_map_s[128] = {0}, hash_map_t[128] = {0};
        for (size_t i(0); i < s.size(); ++i) {
            if (hash_map_s[s[i]] != hash_map_t[t[i]])
                return false;
            hash_map_s[s[i]] = i + 1;
            hash_map_t[t[i]] = i + 1;
        }
        return true;
    }
};
