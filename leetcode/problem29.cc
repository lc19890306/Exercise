class Solution {
public:
    int divide(int dividend, int divisor) {
      // x / 0
        if (divisor == 0)
            return INT_MAX;
	// x / INT_MIN
	// INT_MIN / INT_MIN
        if (divisor == INT_MIN)
            return dividend == INT_MIN ? 1 : 0;
        bool neg((dividend ^ divisor) & (1 << 31) ? true : false);
        int ret(0);
        auto divs(abs(divisor));
        if (dividend == INT_MIN) {
            if (divisor == 1)
	      // INT_MIN / 1
                return INT_MIN;
	    // INT_MIN / x
            dividend += divs;
            ret = 1;
        }
        auto divd(abs(dividend));
        int d(divs);
        while (divs <= divd) {
            d = divs;
            auto counter(1);
            while (d < (divd >> 1)) {
                d <<= 1;
                counter <<= 1;
            }
            divd -= d;
            auto temp(ret + counter);
	    // INT_MIN / -1
            if (counter > 0 && temp < ret)
                return INT_MAX;
            ret = temp;
        }
        
        return neg ? -ret : ret;
    }
};
