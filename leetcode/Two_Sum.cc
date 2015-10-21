class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() < 2) return {};
        vector<int> ret, indices;
        vector<int> temp(nums);
        sort(nums.begin(), nums.end());
        size_t left(0), right(nums.size() - 1);
        while (left < right) {
            auto sum(nums[left] + nums[right]);
            if (sum < target) {
                    ++left;
            }
            else if (target < sum) {
                    --right;
            }
            else {
                indices.push_back(nums[left]);
                indices.push_back(nums[right]);
                break;
            }
        }
        for (size_t i(0); i != temp.size(); ++i)
            if (temp[i] == indices[0] || temp[i] == indices[1]) {
                    ret.push_back(i + 1);
            }
 
        return ret;
    }
};

// Test case {0, 3, 4, 0}, target = 0
// Correct but not neat
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, std::size_t> indices;
        for (std::size_t i(0); i != nums.size(); ++i)
            indices[nums[i]] = i + 1;
        vector<int> ret;
        for (std::size_t i(0); i != nums.size() - 1; ++i) {
            auto it(indices.find(target - nums[i]));
            if (it != indices.end() && it->second != i + 1) {
                ret.push_back(i + 1);
                ret.push_back(it->second);
                return ret;
            }
        }
    }
};

// Comparatively complete
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        if (nums.empty())
            return ret;
        unordered_map<int, vector<int> > hash_map;
        for (int i(0); i < nums.size(); ++i)
            hash_map[nums[i]].push_back(i + 1);
        for (auto &&num : nums)
            if (hash_map.find(target - num) != hash_map.end()) {
                if (target - num == num && hash_map[num].size() < 2)
                    continue;
                else {
                    ret.push_back(hash_map[num].back());
                    hash_map[num].pop_back();
                    ret.push_back(hash_map[target - num].back());
                    hash_map[target - num].pop_back();
                    sort(ret.begin(), ret.end());
                    return ret;
                }
            }
    }
};
