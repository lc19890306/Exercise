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
    int sumNumbers(TreeNode* root, int num = 0) {
        return sum(root, 0);
    }
    
private:
    int sum(TreeNode *root, int val) {
        if (root == nullptr)
            return 0;
        val = val * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr)
            return val;
        return sum(root->left, val) + sum(root->right, val);
    }
};
