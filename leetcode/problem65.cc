class Solution {
public:
    bool isNumber(string s) {
      // skip the leading and trailing whitespaces
        s = strip(s);
	// if s becomes empty after stripping whitespaces
        if (s.empty())
            return false;
        auto it(s.begin());
        auto point_it(s.end()), e_it(s.end()), sign_it(s.begin()), power_sign_it(s.end());
	// check significance
        if (s[0] == '+' || s[0] == '-')
            ++it;
        for (; it != s.end(); ++it) {
            if (!isdigit(*it)) {
                switch ((unsigned char)*it) {
                    case '.': {
                        if (point_it == s.end() &&
                            (isdigit(it[-1]) || isdigit(it[1])) &&
                            it < e_it)
                            point_it = it;
                        else
                            return false;
                    }
                    break;
                    case 'e': {
                        if (e_it == s.end() &&
                            (isdigit(it[-1]) || it[-1] == '.') &&
                            (isdigit(it[1]) || it[1] == '+' || it[1] == '-'))
                            e_it = it;
                        else
                            return false;
                    }
                    break;
                    case '+':
                    case '-': {
                        if (power_sign_it == s.end() &&
                            it - 1 == e_it && 
                            it + 1 != s.end() && 
                            isdigit(it[1]))
                            power_sign_it = it;
                        else
                            return false;
                    }
                    break;
                    default:
                        return false;
                }
            }
        }
        return true;
    }

private:
    string strip(const string &str, const string &chars = " \t") {
        auto begin(str.find_first_not_of(chars));
        if (begin == string::npos)
            return "";
        auto end(str.find_last_not_of(chars) + 1);
        return str.substr(begin, end - begin);
    }
};
