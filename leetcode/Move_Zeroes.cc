class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i(0); i < nums.size(); ++i) {
            if (!nums[i])
                for (int j(i + 1); j < nums.size(); ++j)
                    if (nums[j]) {
                        swap(nums[i], nums[j]);
                        break;
                    }
        }
    }
};

// Use this solution
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        fill(remove(nums.begin(), nums.end(), 0), nums.end(), 0);
    }
};

// Use this solution - the same as the STL solution
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i(0);
	// find the first 0
        while (i < nums.size() && nums[i]) ++i;
	// starting from the first 0, search for the next non-zero and put it in the place of 0
	// treat the entire array as empty (starting from the first 0) and just put in the non-zeroes one by one
        for (int j(i + 1); j < nums.size(); ++j) {
            if (nums[j])
                nums[i++] = nums[j];
        }
	// after put in all the non-zeroes set the remaining places 0
        for (int j(i); j < nums.size(); ++j)
            nums[j] = 0;
    }
};
