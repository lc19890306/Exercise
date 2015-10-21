// O(n^2) time complexity - maybe not the fastest but easy to understand
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff(INT_MAX), ret(0);
        for (int first(0); first < nums.size() - 2;) {
            auto next_target(target - nums[first]);
            int left(first + 1), right(nums.size() - 1);
            while (left < right) {
                auto sum(nums[left] + nums[right]);
                if (abs(sum - next_target) < diff) {
                    diff = abs(sum - next_target);
                    ret = nums[first] + sum;
                }
                if (sum < next_target)
                    do {++left;} while (left < right && nums[left] == nums[left - 1]);
                else
                    do {--right;} while (left < right && nums[right] == nums[right + 1]);
            }
            do {++first;} while (first < nums.size() - 2 && nums[first] == nums[first - 1]);
        }
        return ret;
    }
};
