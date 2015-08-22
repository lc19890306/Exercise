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
