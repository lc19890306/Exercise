// Recursive binary search - O(logn) time complexity
class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMin(nums.begin(), nums.end());
    }
    
private:
    typedef vector<int>::iterator Iterator;
    
    int findMin(Iterator first, Iterator last) {
        if (last - first < 4)
            return *min_element(first, last);
        auto mid(first + ((last - first) >> 1));
        if (*first < *mid && *mid < last[-1])
            return *first;
        if (*first >= *mid && *mid <= last[-1])
	  // MUST use mid + 1 rather than mid because mid may be the minimum and therefore has to be considered in further recursion
            return findMin(first, mid + 1);
        if (*first <= *mid && *mid >= last[-1])
            return findMin(mid + 1, last);
    }
};

// Revised recursive binary search - O(logn) time complexity
class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size() - 1);
    }
    
private:
    int findMin(vector<int> &nums, int left, int right) {
        if (left == right)
            return nums[left];
	// nums[left:right] is sorted if nums[left] < nums[right] and directly return nums[left]
        if (nums[left] < nums[right])
            return nums[left];
        auto mid((left + right) >> 1);
        if (nums[mid] > nums[right])
            return findMin(nums, mid + 1, right);
        else
            return findMin(nums, left, mid);
    }
};

// Iterative binary search solution
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left(0), right(nums.size() - 1);
        while (left < right) {
            if (nums[left] < nums[right])
                return nums[left];
            auto mid((left + right) >> 1);
            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};
