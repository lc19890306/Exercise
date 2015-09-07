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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr)
            return {};
        auto val(to_string(root->val));
        if (root->left == nullptr && root->right == nullptr)
            return {val};
        vector<string> ret;
        auto left(binaryTreePaths(root->left));
        for (auto &&str : left)
            ret.push_back(val + "->" + str);
        auto right(binaryTreePaths(root->right));
        for (auto &&str : right)
            ret.push_back(val + "->" + str);
        return ret;
    }
};
