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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        else if (root->left == nullptr && root->right != nullptr)
            return maxDepth(root->right) + 1;
        else if (root->left != nullptr && root->right == nullptr)
            return maxDepth(root->left) + 1;
        else
            return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }
};
