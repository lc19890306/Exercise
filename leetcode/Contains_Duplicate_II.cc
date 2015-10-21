class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        this->k = k;
        unordered_map<int, vector<int> > hash_map;
        for (int i(0); i != nums.size(); ++i)
            hash_map[nums[i]].push_back(i);
        for (auto &&pair : hash_map)
            if (adjacent_find(pair.second.begin(), pair.second.end(), diff_not_greater_than_k) != pair.second.end())
                return true;
        return false;
    }
    
private:
    static bool diff_not_greater_than_k(const int &num_1, const int &num_2) {
        return num_2 - num_1 <= k;
    }

    static int k;
};

int Solution::k = 0;







// O(n) time and space complexity
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash_map;
        for (int i(0); i != nums.size(); ++i)
            if (hash_map.find(nums[i]) != hash_map.end() && i - hash_map[nums[i]] <= k)
                return true;
            else
                hash_map[nums[i]] = i;
        return false;
    }
};

// Sliding window solution - O(n) time and O(k) space complexity
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hash_table;
        for (int i(0); i != nums.size(); ++i) {
            auto j(i - k - 1);
            if (j >= 0)
                hash_table.erase(nums[j]);
            if (hash_table.find(nums[i]) != hash_table.end())
                return true;
            else
                hash_table.insert(nums[i]);
        }
        return false;
    }
};
