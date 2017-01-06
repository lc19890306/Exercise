// Greedy + BFS solution - O(n) time and space complexity
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<bool> visited(nums.size());
        int ret(0), i(0);
        while (i < nums.size()) {
            int max_range(0), next(0);
            for (int j(1); j <= nums[i] && j < nums.size(); ++j) {
                int neighbor(i + j);
                if (visited[neighbor])
                    continue;
                visited[neighbor] = true;
                int cur_range(neighbor + nums[neighbor]);
                if (neighbor == nums.size() - 1)
                    return ret + 1;
                if (cur_range > max_range) {
                    max_range = cur_range;
                    next = neighbor;
                }
            }
            if (i == next)
                return 0;
            ++ret;
            i = next;
        }
        return ret;
    }
};

// O(n) time and O(1) complexity
class Solution {
public:
    int jump(vector<int>& nums) {
        int ret(0), pos(0);
        while (true) {
            int next_pos(pos);
            for (int i(1), max_range(0); i <= nums[pos] && i < nums.size(); ++i) {
                int neighbor(pos + i);
                int cur_range(neighbor + nums[neighbor]);
                if (neighbor == nums.size() - 1)
                    return ret + 1;
                if (cur_range > max_range) {
                    max_range = cur_range;
                    next_pos = neighbor;
                }
            }
            if (pos == next_pos)
                return 0;
            ++ret;
            pos = next_pos;
        }
        return ret;
    }
};

// // DP solution - O(n^2) time and O(n) space complexity
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int n(nums.size());
//         vector<int> dp(n, INT_MAX);
//         dp[0] = 0;
//         for (int i(1); i < n; ++i) {
//             for (int j(0); j < i; ++j) {
//                 if (j + nums[j] >= i)
//                     dp[i] = min(dp[i], dp[j] + 1);
//             }
//         }
//         return dp.back();
//     }
// };
