// Fastest
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int diff;
	// find the highest bit which differs m from n
        for (int i(30); i >= 0; --i)
            if ((m & (1 << i)) != (n & (1 << i))) {
                diff = i + 1;
                break;
            }
	// remove the different lower bits
        return (n >> diff) << diff;
    }
};

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count(0);
	// remove all different lower bits and count the number of them
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++count;
        }
	// recover the removed lower bits
        return n << count;
    }
};

// Shortest
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int mask(INT_MAX);
	// mask all different lower bits
        while ((m & mask) != (n & mask))
            mask <<= 1;
        return n & mask;
    }
};
