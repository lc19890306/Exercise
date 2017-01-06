// heap solution - O(nlogn) time and O(n) space complexity at worst
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        if (nums.empty())
            return ret;
        k = k > nums.size() ? nums.size() : k;
        priority_queue<pair<int, int> > q;
        for (int i(0); i < k; ++i)
            q.push(make_pair(nums[i], i));
        ret.push_back(q.top().first);
        for (int i(k); i < nums.size(); ++i) {
            while (!q.empty() && q.top().second < i - k + 1)
                q.pop();
            q.push(make_pair(nums[i], i));
            ret.push_back(q.top().first);
        }
        return ret;
    }
};

// Monotonic queue solution - O(n) time and O(k) space complexity
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        if (nums.empty())
            return ret;
        k = k > nums.size() ? nums.size() : k;
	// a "decreasing" deque in terms of the data indexed
	// deque stores indices
        deque<int> q;
        for (int i(0); i < nums.size(); ++i) {
	  // if q.front() is a leading element about to out of window
            if (!q.empty() && q.front() == i - k)
                q.pop_front();
	    // pop all elements smaller than nums[i]
            while (!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();
            q.push_back(i);
	    // starts to write current largest (q.front()) into the final result when i >= k - 1
            if (i >= k - 1)
                ret.push_back(nums[q.front()]);
        }
        return ret;
    }
};
