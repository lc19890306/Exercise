// Backtracking solution O(n) time complexity??
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        auto n(s.size());
        for (int first(1); first < 4 && first < n; ++first) {
            auto str(s.substr(0, first));
            if (!isValid(str))
                continue;
            ip += (str + '.');
            for (int second(first + 1); second < (first + 4); ++second) {
                auto str(s.substr(first, second - first));
                if (!isValid(str))
                    continue;
                ip += (str + '.');
                for (int third(second + 1); third < (second + 4) && third < n; ++third) {
		  // if remaining address is longer than 6, go back directly
                    if (n - second > 6)
                        break;
                    auto str1(s.substr(second, third - second)), str2(s.substr(third));
                    if (!isValid(str1) || !isValid(str2))
                        continue;
                    ip += (str1 + '.' + str2);
                    ret.push_back(ip);
                    for (int i(0); i < n - second + 1; ++i)
                        ip.pop_back();
                }
                ip.pop_back();
                for (int i(0); i < str.length(); ++i)
                    ip.pop_back();
            }
            ip.clear();
        }
        return ret;
    }

    bool isValid(const string &s) {
      // "1135"
        if (s.length() > 3)
            return false;
	// "010"
        if (s.front() == '0' && s.length() > 1)
            return false;
	// "35"
        return stoi(s) <= 255;
    }

    vector<string> ret;
    string ip;
};
