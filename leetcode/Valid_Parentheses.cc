class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> hash_map;
        hash_map.insert({']', '['});
        hash_map.insert({'}', '{'});
        hash_map.insert({')', '('});
        stack<char> stk;
        for (auto &&c : s)
            if (hash_map.find(c) == hash_map.end())
                stk.push(c);
            else if (stk.empty() || stk.top() != hash_map[c])
                return false;
            else
                stk.pop();
        return stk.empty();
    }
};
