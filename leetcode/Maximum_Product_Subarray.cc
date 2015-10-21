// DP solution - O(n) time and O(1) space complexity
// min_end_in_here = min(nums[i], min_end_in_here * nums[i], max_end_in_here * nums[i])
// max_end_in_here = max(nums[i], min_end_in_here * nums[i], max_end_in_here * nums[i])
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product(nums[0]), max_end_in_here(nums[0]), min_end_in_here(nums[0]);
        for (int i(1); i < nums.size(); ++i) {
            auto pair(min_max(nums[i], min_end_in_here * nums[i], max_end_in_here * nums[i]));
            min_end_in_here = pair.first;
            max_end_in_here = pair.second;
            max_product = max(max_product, max_end_in_here);
        }
        return max_product;
    }
    
private:
    pair<int, int> min_max(int a, int b, int c) {
        return make_pair(min(a, min(b, c)), max(a, max(b, c)));
    }
};
