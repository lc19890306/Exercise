// Binary search solution - O(logn) time complexity
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        ret.push_back(lower_bound(nums, target));
        ret.push_back(upper_bound(nums, target));
        return ret;
    }
    
private:
    int lower_bound(vector<int> &nums, int target) {
        if (nums.empty())
            return -1;
        int left(0), right(nums.size() - 1);
        while (left <= right) {
            auto mid((left + right) >> 1);
            if (nums[mid] == target) {
                if (mid == left || nums[mid - 1] < target)
                    return mid;
                else
                    right = mid - 1;
            }
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
    
    int upper_bound(vector<int> &nums, int target) {
        if (nums.empty())
            return -1;
        int left(0), right(nums.size() - 1);
        while (left <= right) {
            auto mid((left + right) >> 1);
            if (nums[mid] == target) {
                if (mid == right || nums[mid + 1] > target)
                    return mid;
                else
                    left = mid + 1;
            }
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};

// equal_range solution
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto pair(equal_range(nums.begin(), nums.end(), target));
        return *pair.first != target ? vector<int>{-1, -1} : vector<int>{pair.first - nums.begin(), pair.second - nums.begin() - 1};
    }
};

// lower_bound and upper_bound solution - should be faster than equal_range solution because upper_bound will not be called if target does not exist in the vector
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lb(lower_bound(nums.begin(), nums.end(), target));
        if (*lb != target)
            return vector<int>{-1, -1};
        auto ub(upper_bound(nums.begin(), nums.end(), target));
        return vector<int>{lb - nums.begin(), ub - nums.begin() - 1};
    }
};
