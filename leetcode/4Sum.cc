class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        vector<vector<int> > ret;
        sort(nums.begin(), nums.end());
        int first_upper(target / 4);
        int first(0);
        while (nums[first] <= first_upper) {
            int second_target(target - nums[first]);
            int second(first + 1);
            int second_upper(second_target / 3);
            while (nums[second] <= second_upper) {
                int third_target(second_target - nums[second]);
                int third(second + 1);
                int third_upper(third_target >> 1);
                int fourth(nums.size() - 1);
                while (third < fourth && nums[third] <= third_upper) {
                    int sum(nums[third] + nums[fourth]);
                    if (third_target < sum) {
                        do {
                            --fourth;
                        } while (third < fourth && nums[fourth] == nums[fourth + 1]);
                    }
                    else if (sum < third_target) {
                        do {
                            ++third;
                        } while (third < fourth && nums[third] == nums[third - 1]);
                    }
                    else {
                        ret.push_back({nums[first], nums[second], nums[third], nums[fourth]});
                        do {
                            ++third;
                        } while (third < fourth && nums[third] == nums[third - 1]);
                        do {
                            --fourth;
                        } while (third < fourth && nums[fourth] == nums[fourth + 1]);
                    }
                }
                do {
                    ++second;
                } while (second < third && nums[second] == nums[second - 1]);
            }
            do {
                ++first;
            } while (first < second && nums[first] == nums[first - 1]);
        }
        return ret;
    }
};
