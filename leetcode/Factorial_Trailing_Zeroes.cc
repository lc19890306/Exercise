// To calculate the number of divisor 5 in n's factorial
class Solution {
public:
    int trailingZeroes(int n) {
        int ret(0);
        while (n > 0) {
            ret += n / 5;
            n /= 5;
        }
        return ret;
    }
};
