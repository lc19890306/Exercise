// Bit-manipulation solution - O(2^n) time complexity
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ret;
        int n(1 << nums.size());
        for (int i(0); i < n; ++i) {
            vector<int> vec;
            for (int j(0), x(i); j < nums.size(); ++j) {
                if (x & 1)
                    vec.push_back(nums[j]);
                x >>= 1;
            }
            ret.push_back(vec);
        }
        return ret;
    }
};

// Optimized bit-manipulation solution
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n(1 << nums.size());
        vector<vector<int> > ret(n);
        for (int i(0); i < nums.size(); ++i)
            for (int j(0); j < n; ++j)
                if ((j >> i) & 1)
                    ret[j].push_back(nums[i]);
        return ret;
    }
};

// Recursive solution - O(2^n) time complexity
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        subsets(nums, 0);
        return ret;
    }
    
private:
    void subsets(vector<int> &nums, int first) {
        ret.push_back(vec);
        for (int i(first); i < nums.size(); ++i) {
            vec.push_back(nums[i]);
            subsets(nums, i + 1);
            vec.pop_back();
        }
    }

    vector<int> vec;
    vector<vector<int> > ret;
};

// Iterative solution - awesome!!
// ret(0) = {{}}
// ret(1) = foreach vec in ret(0) push_back nums[0]
// ret(2) = foreach vec in ret(1) push_back nums[1]
// ret(i) = foreach vec in ret(i - 1) push_back nums[i - 1]
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ret;
        ret.push_back({});
        for (int i(0); i < nums.size(); ++i) {
            int n(ret.size());
            for (int j(0); j < n; ++j) {
                ret.push_back(ret[j]);
                ret.back().push_back(nums[i]);
            }
        }
        return ret;
    }
};
