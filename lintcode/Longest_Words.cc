// O(n) on average
class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        if (dictionary.empty())
            return {};
        hash_map.clear();
        auto max_length(dictionary.front().length());
        for (auto &&str : dictionary) {
            if (str.length() < max_length)
                continue;
            else if (str.length() > max_length)
                max_length = str.length();
            hash_map[str.length()].push_back(str);
        }
        return hash_map[max_length];
    }
    
private:
    unordered_map<long, vector<string> > hash_map;
};

// O(nlogn)
struct shorter {
    bool operator()(const string &lhs, const string &rhs) {
        return lhs.length() < rhs.length();
    }
};
    
    class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        if (dictionary.empty())
            return {};
        for (auto &&str : dictionary)
            q.push(str);
        vector<string> ret;
        auto max_length(q.top().length());
        while (!q.empty() && q.top().length() == max_length) {
            ret.push_back(q.top());
            q.pop();
        }
        return ret;
    }
    
private:
    priority_queue<string, vector<string>, shorter> q;
};
