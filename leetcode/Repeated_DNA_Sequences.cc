class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() < 10)
            return {};
        unordered_map<int, bool> hash_map;
        vector<string> ret;
        for (int i(0); i < s.length() - 9; ++i) {
            auto str(s.substr(i, 10));
            auto key(encode(str));
            if (hash_map.find(key) == hash_map.end())
                hash_map[key] = false;
            else if (!hash_map[key]) {
                hash_map[key] = true;
                ret.push_back(str);
            }
        }
        return ret;
    }
    
private:
  // In octal, 'A' is 0101, 'C' is 0103, 'G' is 0107, 'T' is 0124, the last digit can be used to differentiate them, namely 1, 3, 7, 4, which need 3 bits, so a 10-letter substring need 30 bits for encoding
    int encode(const string &s) {
        int ret(0);
        for (int i(0); i < 10; ++i)
	  // s[i] & 7 to get the last 3 bits (last digit in octal)
	  // ret << 3 and then pad the last 3 bits
            ret = (ret << 3) | (s[i] & 7);
        return ret;
    }
};
