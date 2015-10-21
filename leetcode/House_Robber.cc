// Pure recursive solution - TLE
class Solution {
public:
    int rob(vector<int>& nums) {
        return rob(nums.begin(), nums.end());
    }
    
private:
    typedef vector<int>::iterator Iterator;
    int rob(Iterator first, Iterator last) {
        if (first == last)
            return 0;
        auto count(distance(first, last));
        if (count == 1)
            return *first;
        if (count == 2)
            return max(*first, first[1]);
        return max(*first + rob(first + 2, last), first[1] + rob(first + 3, last));
    }
};

// DP solution - O(n) time and space complexity
// total[i][0]: skip the i-th house
// total[i][1]: rob the i-th house
// total[i][0] = max(total[i - 1][0], total[i - 1][1]) if skip the i-th house, total amount should be the maximum amount after checking the previous (i - 1) houses
// total[i][1] = total[i - 1][0] + nums[i - 1] if rob the i-th house, total amount should be the summation of total[i - 1][0] (the total amount after skipping the (i-1)-th house) and the amount in current house nums[i - 1] (should be nums[i] if starts with 1 instead of 0)
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<vector<int> > total(nums.size() + 1, vector<int>(2));
        total[0][0] = total[0][1] = 0;
        for (int i(1); i < total.size(); ++i) {
            total[i][0] = max(total[i - 1][0], total[i - 1][1]);
            total[i][1] = total[i - 1][0] + nums[i - 1];
        }
        return max(total.back()[0], total.back()[1]);
    }
};

// Optimized DP solution - O(n) time and O(1) space complexity
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int total_not_rob(0), total_rob(nums[0]);
        for (int i(1); i < nums.size(); ++i) {
            auto total_not_rob_prev(total_not_rob);
            total_not_rob = max(total_not_rob, total_rob);
            total_rob = total_not_rob_prev + nums[i];
        }
        return max(total_not_rob, total_rob);
    }
};

// Further revised DP solution - O(n) time and O(1) space complexity
class Solution {
public:
    int rob(vector<int>& nums) {
        int total_not_rob(0), total_rob(0);
        for (int i(0); i < nums.size(); ++i) {
            auto total_not_rob_prev(total_not_rob);
            total_not_rob = max(total_not_rob, total_rob);
            total_rob = total_not_rob_prev + nums[i];
        }
        return max(total_not_rob, total_rob);
    }
};
