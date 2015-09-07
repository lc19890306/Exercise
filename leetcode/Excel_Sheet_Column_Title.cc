class Solution {
public:
    string convertToTitle(int n) {
        if (n < 1)
            return "";
        string ret;
        while (n) {
            int step(n % 26);
            if (step == 0) {
                ret = char('Z') + ret;
                n = n / 26 - 1;
            }
            else {
                ret = char('@' + step) + ret;
                n /= 26;
            }
        }
        return ret;
    }
};
