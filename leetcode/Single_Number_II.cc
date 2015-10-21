// O(n) time and O(1) space complexity
// for each bit, count the total number of 1 in all elements, since each number (except one) appears three times, for each bit, count % 3 is the final result bit for the only one element
class Solution {
public:
  // test case {0, 0, 0, 5}
  // in binary: 000, 000, 000, 101
  // so the count for each bit is 101
  // and the final result is 1%3, 0%3, 1%3, namely, 101 = 5
    int singleNumber(vector<int>& nums) {
        vector<int> bit(32);
        for (auto &&num : nums) {
            for (int i(0); i < 32 && num != 0; ++i) {
                bit[i] += num & 1;
                num >>= 1;
            }
        }
        int ret(0);
        for (int i(0); i < 32; ++i)
            ret |= (bit[i] % 3 ? (1 << i) : 0);
        return ret;
    }
};
