// O(n) time and space complexity
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> hash_table;
        for (auto &&num : nums) {
            auto it(hash_table.find(num));
            if (it != hash_table.end())
                hash_table.erase(it);
            else
                hash_table.insert(num);
        }
        vector<int> ret;
        for (auto &&num : hash_table)
            ret.push_back(num);
        return ret;
    }
};

// O(n) time and O(1) space complexity
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_ret(0);
	// xor all the numbers and get the xor result of the final two elements a and b
        for (auto &&num : nums)
            xor_ret ^= num;
	// since a must be different from b
	// xor_ret (a xor b) must not be 0
	// so find any bit equal to 1
	// x & ~(x - 1) get the lowest bit equal to 1
	// use this bit to differentiate a from b
        xor_ret &= ~(xor_ret - 1);
        vector<int> ret(2);
	// xor all the numbers where this bit equals 1 and finally get a
        for (auto &&num : nums)
            if (num & xor_ret)
                ret[0] ^= num;
	// xor all the numbers where this bit equals 0 and finally get b
            else
                ret[1] ^= num;
        return ret;
    }
};
