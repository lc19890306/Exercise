// 4 : 0100
// -4: 1100
// 5 : 0101
// -5: 1011
class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        // write your code here
        return n > 0 && n == (n & -n);
    }
};
