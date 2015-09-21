// WRONG solution - not in-place
// Preorder traversal - O(n) time and space complexity
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
    void flatten(TreeNode* root) {
        if (!root)
            return;
	// cache left and right first because they may be modified in the following recursions
        auto left(root->left), right(root->right);
        if (!nodes.empty()) {
            nodes.back()->right = root;
            nodes.back()->left = nullptr;
        }
        nodes.push_back(root);
        flatten(left);
        flatten(right);
    }
    
private:
    vector<TreeNode *> nodes;
};

// Recursive solution
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
    void flatten(TreeNode* root) {
        flatten_helper(root);
    }
    
private:
    TreeNode *flatten_helper(TreeNode *root) {
        if (!root || !root->left && !root->right)
            return root;
        auto left_last(flatten_helper(root->left));
        if (left_last) {
            left_last->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
	// if left_last is nullptr, the entire left subtree is nullptr, traverse right subtree
	// otherwise directly traverse from left_last
        return left_last ? flatten_helper(left_last) : flatten_helper(root->right);
    }
};
