class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        int counter(0);
        for (auto &&pair : bits) {
            if (n & pair.first)
                ++counter;
            if (counter > 1)
                return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        return !(n & (n - 1));
    }
};
