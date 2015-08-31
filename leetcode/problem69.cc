// Newton's method
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return x;
        double precision(1e-1);
        double ret(x);
        double last;
        do {
            last = ret;
            ret = (ret + x / ret) * 0.5;
        } while (abs(ret - last) > precision);
        return (int)ret;
    }
};

// Binary search
class Solution {
public:
    int mySqrt(int x) {
        uint64_t left(0), right(x);
        while (left <= right) {
            auto mid((left + right) >> 1);
            auto mid_square(mid * mid);
            if (mid_square <= x && x < (mid + 1) * (mid + 1))
                return mid;
            if (mid_square > x)
                right = mid - 1;
            else
                left = mid + 1;
        }
    }
};
