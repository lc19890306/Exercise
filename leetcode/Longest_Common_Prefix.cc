class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        auto common_prefix(strs[0]);
        for (int i(1); i < strs.size(); ++i)
            common_prefix = commonPrefix(common_prefix, strs[i]);
        return common_prefix;
    }
    
private:
    string commonPrefix(string a, string b) {
        int length(min(a.length(), b.length()));
        for (int i(0); i < length; ++i)
            if (a[i] != b[i])
                return a.substr(0, i);
	// the longer string begins with the shorter string
	// return the shorter string
        return a.length() == length ? a : b;
    }
};
