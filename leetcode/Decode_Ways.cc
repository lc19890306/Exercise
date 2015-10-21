// if s[i] is not '0', ret[i] += ret[i - 1] because s[i] alone is valid
// if s[i - 1 : i] is valid, ret[i] += ret[i - 2] because s[i - 1 : i] is valid
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty())
            return 0;
        s = '1' + s;
        vector<int> ret(s.length());
        ret[0] = 1;
	// test case: "0"
        ret[1] = ('0' == s[1] ? 0 : 1);
        for (int i(2); i < s.length(); ++i) {
            string str;
            str += s[i - 1];
            str += s[i];
	    // "0" alone is invalid
            ret[i] = ('0' == s[i] ? 0 : ret[i - 1]) + (isValid(str) ? ret[i - 2] : 0);
        }
        return ret.back();
    }
    
private:
    bool isValid(string s) {
      // test case: "201"
        if ('0' == s.front())
            return false;
        auto num(stoi(s));
        return 0 < num && num < 27; 
    }
};

// Optimized solution - O(n) time and space complexity
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty())
            return 0;
        s = '1' + s;
        vector<int> ret(s.length());
        ret[0] = 1;
        ret[1] = ('0' == s[1] ? 0 : 1);
        for (int i(2); i < s.length(); ++i)
            ret[i] = ('0' == s[i] ? 0 : ret[i - 1]) + (isValid(s[i - 1], s[i]) ? ret[i - 2] : 0);
        return ret.back();
    }
    
private:
    bool isValid(const char &a, const char &b) {
        return '1' == a or '2' == a and b < '7';
    }
};
