class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> hash_map_p;
        unordered_map<string, char> hash_map_s;
        istringstream input(str);
        string word;
        int i(0);
	// judge i first otherwise istringstream would be modified
	// test case: "", "beef"
        while (i < pattern.length() && input >> word) {
            if (hash_map_p.find(pattern[i]) == hash_map_p.end() && hash_map_s.find(word) == hash_map_s.end()) {
                hash_map_p[pattern[i]] = word;
                hash_map_s[word] = pattern[i];
            }
            else if (hash_map_p[pattern[i]] != word || hash_map_s[word] != pattern[i])
                return false;
	    // modify i at last
            ++i;
        }
	// length of pattern is less than the number of words in str
	// OR the number of words is less than the length of pattern
        if (input >> word || i < pattern.length())
            return false;
        return true;
    }
};
