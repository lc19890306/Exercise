// Too complicated!
// max_diff is the remaining part of INT_MAX except for the first digit 2
// min_diff is the remaining part of INT_MIN except for the first digit 2
// counter is the number of digits of x
// init is the first digit of current ret (the last digit of current x)
class Solution {
public:
    int reverse(int x) {
        const int max_diff(INT_MAX - 2e9);
        const int min_diff(max_diff - 1);
        int sign(1);
        if (x < 0) {
            sign = -1;
            x = -x;
        }
        int counter(0);
        int ret(0);
        int init(0);
        while (x > 0) {
            ++counter;
            if (counter == 11) {
                if (init > 2)
                    return 0;
                if (init == 2) {
                    ret -= 2e8;
                    int diff = ret * 10 + x % 10;
                    if (sign == 1) {
                        if (diff >= max_diff)
                            return 0;
                        else
                            return diff + 2e9;
                    }
                    else {
                        if (diff >= min_diff)
                            return 0;
                        else
                            return -diff-2e9;
                    }
                }
            }
            else if (counter == 1)
                init = x % 10;
            else {
                ret = ret * 10 + x % 10;
                x /= 10;
            }
        }
        return ret * sign;
    }
};

// Using long long may not be a perfect solution
class Solution {
public:
    int reverse(int x) {
        long long ret(0);
        while (x) {
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        if (ret < INT_MIN || ret > INT_MAX)
            return 0;
        return ret;
    }
};
