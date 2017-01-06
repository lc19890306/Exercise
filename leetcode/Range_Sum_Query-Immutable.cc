// DP solution - O(1) time and O(n) space complexity
// range[i:j] = range[0:j] - range[0:i-1]
class NumArray {
public:
    NumArray(vector<int> &nums) {
        sums.push_back(0);
        for (int i(0); i < nums.size(); ++i)
            sums.push_back(sums.back() + nums[i]);
    }

    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
    
private:
    vector<int> sums;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

// almost the same as the above solution
class NumArray {
public:
    NumArray(vector<int> &nums) {
        if (nums.empty())
            return;
        sums.resize(nums.size() + 1);
        for (int i(0); i < nums.size(); ++i)
            sums[i + 1] = sums[i] + nums[i];
    }

    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
    
private:
    vector<int> sums;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
