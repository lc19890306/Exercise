const int MAX_HEAD = INT_MAX / 10;
class Solution {
public:
    int myAtoi(string str) {
        if (str.empty())
            return 0;
        int ret(0);
        int sign(1);
        str = strip(str);
        str = split(str);
        if (str.empty())
            return 0;
        auto it(str.begin());
        if (str[0] == '+')
            ++it;
        if (str[0] == '-') {
            sign = -1;
            ++it;
        }
        for (; it != str.end(); ++it) {
            if (isdigit(*it)) {
                auto tail(*it - '0');
                if (ret < MAX_HEAD)
                    ret = ret * 10 + tail;
                else if (sign == 1) {
                    if (ret == MAX_HEAD && tail > 7 ||
                        ret > MAX_HEAD)
                        return INT_MAX;
                    else
                        ret = ret * 10 + tail;
                }
                else if (sign == -1) {
                    if (ret == MAX_HEAD && tail > 8 ||
                        ret > MAX_HEAD)
                        return INT_MIN;
                    else
                        ret = ret * 10 + tail;
                }
            }
            else
                return ret * sign;
        }
        return ret * sign;
    }
    
private:
    string strip(const string &str, const string &chars = " \t") {
        auto begin(str.find_first_not_of(chars));
        if (begin == string::npos)
            return str;
        auto end(str.find_last_not_of(chars) + 1);
        return str.substr(begin, end - begin);
    }
    
    string split(const string &str, const string &delim = " \t.") {
        auto end(str.find_first_of(delim));
        if (end == string::npos)
            return str;
        return str.substr(0, end);
    }
};

// Only need to handle 4 cases:
// 1. discard all leading spaces;
// 2. sign of the number;
// 3. overflow;
// 4. invalid input
const int MAX_HEAD = INT_MAX / 10;
class Solution {
public:
    int myAtoi(string str) {
        int ret(0);
        int sign(1);
        str = strip(str);
        auto it(str.begin());
        if (str[0] == '+')
            ++it;
        if (str[0] == '-') {
            sign = -1;
            ++it;
        }
        for (; it != str.end(); ++it) {
            if (isdigit(*it)) {
                auto tail(*it - '0');
                if (ret == MAX_HEAD && tail > 7 ||
                    ret > MAX_HEAD)
                    return sign == 1 ? INT_MAX : INT_MIN;
                else    
                    ret = ret * 10 + tail;
            }
            else
                return ret * sign;
        }
        return ret * sign;
    }
    
private:
    string strip(const string &str, const string &chars = " \t") {
        auto begin(str.find_first_not_of(chars));
        return begin == string::npos ? "" : str.substr(begin);
    }
};
