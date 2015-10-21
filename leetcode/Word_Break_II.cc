// Memorization DFS solution - O(n^2) time complexity
// cache intermediate results for current string s in order to avoid duplicated recursion
// test case: "cat sand dog" and "cats and dog", "dog" should be cached
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        if (hash_map.find(s) != hash_map.end())
            return hash_map[s];
        for (int i(1); i <= s.length(); ++i) {
            auto key(s.substr(0, i));
            if (wordDict.find(key) != wordDict.end()) {
                for (auto &&str : wordBreak(s.substr(i), wordDict))
                    hash_map[s].push_back(key + " " + str);
		// if key is the trailing string in s, push it directly into the results
		// test case: a in "a"
                if (i == s.length())
                    hash_map[s].push_back(key);
            }
        }
        return hash_map[s];
    }
    
private:
    unordered_map<string, vector<string> > hash_map;
};
