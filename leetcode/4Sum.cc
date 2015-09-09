// Dedicated version
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

// General version - recursive
class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        return kSum(nums.begin(), nums.end(), 4, target);
    }
    
private:
    typedef vector<int>::iterator Iterator;
    
    vector<vector<int> > kSum(Iterator first, Iterator last, const int &k, const int &target) {
        vector<vector<int> > ret;
        if (k == 2) {
            auto left(first), right(last - 1);
            while (left < right) {
                auto sum(*left + *right);
                if (sum < target)
                    do {
                        ++left;
                    } while (left < right && *left == left[-1]);
                else if (target < sum)
                    do {
                        --right;
                    } while (left < right && *right == right[1]);
                else {
                    ret.push_back({*left, *right});
                    do {
                        ++left;
                    } while (left < right && *left == left[-1]);
                    do {
                        --right;
                    } while (left < right && *right == right[1]);
                }
            }
        }
        else {
            for (auto it(last - 1); it != first + k - 2; --it) {
                if (it != last - 1 && *it == it[1])
                    continue;
                auto temp(kSum(first, it, k - 1, target - *it));
                for (auto &&vec : temp) {
                    vec.push_back(*it);
                    ret.push_back(vec);
                }
            }
        }
        return ret;
    }
};
