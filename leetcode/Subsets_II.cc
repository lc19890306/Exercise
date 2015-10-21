// Iterative solution
// ret(0) = {{}}
// ret(1) = foreach vec in ret(0) push_back nums[0]
// ret(2) = foreach vec in ret(1) push_back nums[1]
// ret(i) = foreach vec in ret(i - 1) push_back nums[i - 1]
// if nums[i] != nums[i - 1], count the number of vectors newly added (dup_size)
// then if nums[i] == nums[i - 1], only add nums[i] to the dup_size vectors in the back of ret
// test case [1, 2, 2, 2]
// 1. {}, {1}, dup_size = 1
// 2. {}, {1}, {2}, {1, 2}, dup_size = 2, 2 is different from 1, add 2 to {} and {1}
// 3. {}, {1}, {2}, {1, 2}, {1, 2, 2}, {2, 2}, dup_size = 2, still 2, add 2 to {1, 2} and {2}
// 4. {}, {1}, {2}, {1, 2}, {1, 2, 2}, {2, 2}, {2, 2, 2}, {1, 2, 2, 2}, dup_size = 2, still 2, add 2 to {2, 2} and {1, 2, 2}
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > ret;
        if (nums.empty())
            return ret;
        sort(nums.begin(), nums.end());
        ret.push_back({});
        ret.push_back({nums.front()});
        int dup_size(1);
        for (int i(1); i < nums.size(); ++i) {
            int size(ret.size());
            if (nums[i] == nums[i - 1]) {
                for (int j(size - 1); j > size - dup_size - 1; --j) {
                    ret.push_back(ret[j]);
                    ret.back().push_back(nums[i]);
                }
            }
            else {
                dup_size = ret.size();
                for (int j(0); j < size; ++j) {
                    ret.push_back(ret[j]);
                    ret.back().push_back(nums[i]);
                }
            }
        }
        return ret;
    }
};

// Recursive backtracking solution - O(2^n) time complexity
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        subsetsWithDup(nums, 0);
        return ret;
    }
    
private:
    void subsetsWithDup(vector<int> &nums, int begin) {
        ret.push_back(vec);
        for (int i(begin); i < nums.size(); ++i) {
            if (i == begin || nums[i] != nums[i - 1]) {
                vec.push_back(nums[i]);
                subsetsWithDup(nums, i + 1);
                vec.pop_back();
            }
        }
    }
    
    vector<int> vec;
    vector<vector<int> > ret;
};
