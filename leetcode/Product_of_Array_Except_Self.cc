// O(n) time complexity - use division which is NOT allowed
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret;
        int count(0);
        long long product(1);
        for (auto &&num : nums)
            if (!num)
                ++count;
            else
                product *= num;
        if (count > 1)
            fill_n(back_inserter(ret), nums.size(), 0);
        else if (count == 1)
            for (auto &&num : nums)
                if (!num)
                    ret.push_back(product);
                else
                    ret.push_back(0);
        else
            for (auto &&num : nums)
                ret.push_back(product / num);
        return ret;
    }
};

// O(n) time complexity
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size());
	// iterate forwards
        ret[0] = 1;
        for (int i(1); i < nums.size(); ++i)
            ret[i] = ret[i - 1] * nums[i - 1];
	// iterate backwards
        for (int i(nums.size() - 1), right(1); i >= 0; right *= nums[i--])
            ret[i] *= right;
        return ret;
    }
};
