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
