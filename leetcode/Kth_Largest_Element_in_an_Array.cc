// heap solution - O((n + k)logn) time complexity
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for (auto &&num : nums)
            q.push(num);
        while (--k > 0)
            q.pop();
        return q.top();
    }
};

// Optimized heap solution - O(nlogk) time complexity
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      // use minimum heap instead of maximum heap to guarantee that the minimum element in heap is the k-th largest in k elements
        priority_queue<int, vector<int>, greater<int> > q;
        for (auto &&num : nums) {
            q.push(num);
            if (q.size() > k)
                q.pop();
        }
        return q.top();
    }
};

// sort solution - O(nlogn) time complexity
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
};

// Introsort solution - O(n) time complexity on average - fastest
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k - 1];
    }
};
