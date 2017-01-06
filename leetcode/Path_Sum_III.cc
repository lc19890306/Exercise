// O(n) time and O(n) space complexity
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        sum_paths[0] = 1;
        return helper(root, 0, sum);
    }
    
    int helper(TreeNode* root, const int pre_sum, const int target) {
        if (!root) return 0;
        const int sum = pre_sum + root->val;
        int res = 0;
        if (sum_paths.count(sum - target) > 0) {
            res = sum_paths[sum - target];
        }
        ++sum_paths[sum];
        res += helper(root->left, sum, target) + helper(root->right, sum, target);
        --sum_paths[sum]; // must decrement to avoid unnecessary impact to other path search
        return res;
    }
    
    unordered_map<int, int> sum_paths;
};
