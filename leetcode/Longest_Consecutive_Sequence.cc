// O(n) time and space complexity
// case: 100, 4, 200, 1, 3, 2
// 1. put all numbers into the hash_table
// 2. iterates all the numbers
// 3. check 100: in hash_table, ++cur_len, remove 100
// 4. check 101: not in hash_table, cur_len unchanged
// 5. check 99: not in hash_table, cur_len unchanged
// 6. update max_len
// 7. check 4: in hash_table, ++cur_len, remove 4
// 8. check 5: not in hash_table, cur_len unchanged
// 9. check 3: in hash_table, ++cur_len, remove 3
// 10. check 2: in hash_table, ++cur_len, remove 2
// 11. check 1: in hash_table, ++cur_len, remove 1
// 12. check 0: not in hash_table, cur_len unchanged
// 13. update max_len
// 14. check 200: in hash_table, ++cur_len, remove 200
// 15. check 201: not in hash_table, cur_len unchanged
// 16. check 199: not in hash_table, cur_len unchanged
// 17. update max_len
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_len(0);
        unordered_set<int> hash_table(nums.begin(), nums.end());
        for (int i(0); i < nums.size() && !hash_table.empty(); ++i) {
            int cur_len(0), cur_num(nums[i]);
            while (hash_table.find(cur_num) != hash_table.end()) {
                hash_table.erase(cur_num);
                ++cur_num;
                ++cur_len;
            }
            cur_num = nums[i] - 1;
            while (hash_table.find(cur_num) != hash_table.end()) {
                hash_table.erase(cur_num);
                --cur_num;
                ++cur_len;
            }
            max_len = max(max_len, cur_len);
        }
        return max_len;
    }
};
