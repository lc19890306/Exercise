class Solution {
public:
    int compareVersion(string version1, string version2) {
        Version v1(version1), v2(version2);
        return cmp(v1, v2);
    }
    
private:
    struct Version {
        Version(const string &v) {
            int left(0);
            for (int right(v.find(".")); right != string::npos; right = v.find(".", left)) {
                strs.push_back(lstrip(v.substr(left, right - left), "0"));
                left = right + 1;
            }
            strs.push_back(lstrip(v.substr(left, v.length() - left), "0"));
        }

      // 00001.0000.0000.001.200 ==> 1...1.200
        string lstrip(const string &str, const string &targets) {
            auto left(str.find_first_not_of(targets));
            if (left == string::npos)
                return "";
            return str.substr(left, str.length() - left);
        }

        vector<string> strs;
    };
    
    int cmp(const Version &v1, const Version &v2) {
        auto min_size(min(v1.strs.size(), v2.strs.size()));
        for (int i(0); i < min_size; ++i) {
	  // 2.0 < 10.1
            if (v1.strs[i].length() < v2.strs[i].length())
                return -1;
	    // 10.1 > 2.0
            if (v1.strs[i].length() > v2.strs[i].length())
                return 1;
	    // 10.1 < 23.2
            if (v1.strs[i] < v2.strs[i])
                return -1;
	    // 23.2 > 10.1
            if (v1.strs[i] > v2.strs[i])
                return 1;
        }
	// 10.0.0.0 == 10
        if (min_size == v1.strs.size() && min_size < v2.strs.size())
            for (int i(v2.strs.size() - 1); i >= min_size; --i)
                if (!v2.strs[i].empty())
                    return -1;
        if (min_size == v2.strs.size() && min_size < v1.strs.size())
            for (int i(v1.strs.size() - 1); i >= min_size; --i)
                if (!v1.strs[i].empty())
                    return 1;
        return 0;
    }
};
