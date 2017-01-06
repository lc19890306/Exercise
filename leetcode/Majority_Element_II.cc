// Boyer-Moore Voting Algorithm - O(n) time and O(1) space complexity
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1(0), count2(0), candidate1(0), candidate2(1);
        for (auto &&num : nums) {
            if (candidate1 == num)
                ++count1;
            else if (candidate2 == num)
                ++count2;
            else if (0 == count1) {
                candidate1 = num;
                count1 = 1;
            }
            else if (0 == count2) {
                candidate2 = num;
                count2 = 1;
            }
            else {
                --count1;
                --count2;
            }
        }
        count1 = count2 = 0;
        vector<int> ret;
        for (auto &&num : nums) {
            if (num == candidate1)
                ++count1;
            else if (num == candidate2)
                ++count2;
        }
        if (count1 > nums.size() / 3)
            ret.push_back(candidate1);
        if (count2 > nums.size() / 3)
            ret.push_back(candidate2);
        return ret;
    }
};
