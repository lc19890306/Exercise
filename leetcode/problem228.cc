bool diff_not_equals_1(int &num_1, int &num_2) {
    return num_2 - num_1 != 1;
}

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        auto left(nums.begin()), right(left);
        for (auto it(nums.begin()); it != nums.end(); it = right + 1) {
            left = it;
            right = adjacent_find(left, nums.end(), diff_not_equals_1);
            if (right == nums.end())
                --right;
            string s(to_string(*left));
            if (left < right) {
                s += "->";
                s += to_string(*right);
            }
            ret.push_back(s);
        }
        return ret;
    }
};
