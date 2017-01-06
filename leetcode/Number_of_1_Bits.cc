class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res(0);
        do {
            if (n & 1)
                ++res;
        } while (n >>= 1);
        return res;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count(0);
        while (n > 0) {
            count += (n & 1);
            n >>= 1;
        }
        return count;
    }
};
