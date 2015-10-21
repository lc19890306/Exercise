// Two points solution - O(n) time complexity
// Similar to sliding window
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start(0), sum(0), min_length(INT_MAX);
        for (int i(0); i < nums.size(); ++i) {
            sum += nums[i];
            while (sum >= s) {
                min_length = min(min_length, i - start + 1);
                sum -= nums[start++];
            }
        }
        return min_length == INT_MAX ? 0 : min_length;
    }
};

// Binary search solution - O(nlogn) time and O(n) space complexity
// the entire solution is actually very trivial
// intuitively, if we wanna find the subarray with minimum length, we just check each element and search backwards from the element to see whether the summation is greater than or equal to s, the entire time will be O(n^2)
// however, if we build an ascending sorted array by accumulating elements from 0 to i, the "backward" search will become much easier and we can just use binary search to reduce the entire time to O(nlogn)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int min_length(INT_MAX);
        vector<int> sums(nums.size() + 1);
	// create an ascending sorted array
        accumulate(nums, sums);
        for (int i(1); i < sums.size(); ++i) {
            if (sums[i] >= s) {
                auto pos(upper_bound(sums, 0, i, sums[i] - s));
                if (pos != -1)
                    min_length = min(min_length, i - pos + 1);
            }
        }
        return min_length == INT_MAX ? 0 : min_length;
    }
    
private:
    void accumulate(const vector<int> &nums, vector<int> &sums) {
        for (int i(1); i < sums.size(); ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
    }
    
    int upper_bound(const vector<int> &sums, int left, int right, int target) {
        while (left < right) {
            auto mid((left + right) >> 1);
            if (sums[mid] > target)
                right = mid;
            else
                left = mid + 1;
        }
        return sums[right] > target ? right : -1;
    }
};
