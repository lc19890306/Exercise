// use sorted str as key for hash_map
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > hash_map;
        for (auto &&str : strs)
            hash_map[strsort(str)].push_back(str);
        vector<vector<string> > ret(hash_map.size());
        size_t i(0);
        for (auto &&pair : hash_map) {
            ret[i].swap(pair.second);
            sort(ret[i].begin(), ret[i].end());
            ++i;
        }
        return ret;
    }
    
private:
    string strsort(const string &str) {
        int count[26] = {0};
        for (auto &&c : str)
            ++count[c - 'a'];
        string ret(str.size(), 'a');
        int j(-1);
        for (int i(0); i != 26; ++i)
            while (count[i]-- > 0)
                ret[++j] += i;
        return ret;
    }
};

// use prime product as key for hash_map
const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<long, vector<string> > hash_map;
        for (auto &&str : strs)
            hash_map[key(str)].push_back(str);
        vector<vector<string> > ret(hash_map.size());
        size_t i(0);
        for (auto &&pair : hash_map) {
            ret[i].swap(pair.second);
            sort(ret[i].begin(), ret[i].end());
            ++i;
        }
        return ret;
    }
    
private:
    long key(const string &str) {
        long ret(1);
        for (auto &&c : str)
            ret *= primes[c - 'a'];
        return ret;
    }
};
