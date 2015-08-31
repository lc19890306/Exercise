class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            n = -n;
            x = 1 / x;
        }
        double ret(1);
        while (n > 0) {
            if (n & 1)
                ret *= x;
            x *= x;
            n >>= 1;
        }
        return ret;
    }
};

class Solution {
public:
    double myPow(double x, int n) {
      // same as while (n > 0)
        if (n == 0)
            return 1;
        if (n < 0) {
            n = -n;
            x = 1 / x;
        }
	// each round x *= x so the input base is x * x
	// if n & 1 == 1, ret *= x, so use x * the return value of myPow
        return n & 1 ? x * myPow(x * x, n >> 1) : myPow(x * x, n >> 1);
    }
};
