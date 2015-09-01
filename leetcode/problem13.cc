// Faster than hashmap
class Solution {
public:
    int romanToInt(string s) {
        int ret(0);
        for (auto rit(s.rbegin()); rit != s.rend(); ++rit) {
            switch (*rit) {
                case 'I': {
                    if (rit != s.rbegin() &&
                        ('V' == rit[-1] || 'X' == rit[-1]))
                        --ret;
                    else
                        ++ret;
                }
                break;
                case 'V': {
                    ret += 5;
                }
                break;
                case 'X': {
                    if (rit != s.rbegin() &&
                        ('L' == rit[-1] || 'C' == rit[-1]))
                        ret -= 10;
                    else
                        ret += 10;
                }
                break;
                case 'L': {
                    ret += 50;
                }
                break;
                case 'C': {
                    if (rit != s.rbegin() &&
                        ('D' == rit[-1] || 'M' == rit[-1]))
                        ret -= 100;
                    else
                        ret += 100;
                }
                break;
                case 'D': {
                    ret += 500;
                }
                break;
                case 'M': {
                    ret += 1000;
                }
                break;
                default:
                break;
            }
        }
        return ret;
    }
};

unordered_map<string, int> hash_map {
    {"I", 1},
    {"IV", 4},
    {"V", 5},
    {"IX", 9},
    {"X", 10},
    {"XL", 40},
    {"L", 50},
    {"XC", 90},
    {"C", 100},
    {"CD", 400},
    {"D", 500},
    {"CM", 900},
    {"M", 1000}
};

class Solution {
public:
    int romanToInt(string s) {
        int ret(0);
        int i(s.size() - 2);
        for (; i >= 0; i -= 2) {
            auto it(hash_map.find(s.substr(i, 2)));
            if (it != hash_map.end())
                ret += it->second;
            else {
                auto it(hash_map.find(s.substr(i + 1, 1)));
                ret += it->second;
                ++i;
            }
        }
        if (i == -1) {
            auto it(hash_map.find(s.substr(0, 1)));
            ret += it->second;
        }
        return ret;
    }
};
