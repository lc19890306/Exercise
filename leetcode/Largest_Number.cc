class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        string ret;
        for (auto &&num : nums)
            strs.push_back(to_string(num));
        sort(strs.begin(), strs.end(), greater());
        for (auto &&str : strs)
            ret += str;
	// case: {}, {0, 0, 0}
        return !ret.empty() && '0' == ret.front() ? "0" : ret;
    }
    
private:
    struct greater {
      // AWESOME!!!
        bool operator()(const string &lhs, const string &rhs) {
            auto x(lhs + rhs), y(rhs + lhs);
            return x > y;
        }
    };
};
