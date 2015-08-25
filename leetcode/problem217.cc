class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return unique(nums.begin(), nums.end()) != nums.end();
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash_table;
        for (auto &&num : nums)
            if (hash_table.find(num) == hash_table.end())
                hash_table.insert(num);
            else
                return true;
        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (size_t i(1); i < nums.size(); ++i)
            if (nums[i] == nums[i - 1])
                return true;
        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return adjacent_find(nums.begin(), nums.end()) != nums.end();
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
    }
};

