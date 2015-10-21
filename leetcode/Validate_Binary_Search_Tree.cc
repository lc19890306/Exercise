// Postorder traversal
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
    bool isValidBST(TreeNode* root) {
        long smallest(LONG_MAX), largest(LONG_MIN);
        return isValidBST(root, smallest, largest);
    }
    
private:
    bool isValidBST(TreeNode *root, long &smallest, long &largest) {
        if (!root)
            return true;
        smallest = min(smallest, (long)root->val);
        largest = max(largest, (long)root->val);
        long left_largest(LONG_MIN), right_smallest(LONG_MAX);
        if (!isValidBST(root->left, smallest, left_largest) || !isValidBST(root->right, right_smallest, largest))
            return false;
        if (left_largest >= root->val || root->val >= right_smallest)
            return false;
        smallest = min(smallest, right_smallest);
        largest = max(largest, left_largest);
        return true;
    }
};

// Inorder traversal
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
    bool isValidBST(TreeNode* root) {
        TreeNode *largest = nullptr;
        return isValidBST(root, largest);
    }
    
private:
    bool isValidBST(TreeNode *root, TreeNode *&largest) {
        if (!root)
            return true;
        if (!isValidBST(root->left, largest))
            return false;
	// MUST be >= rather than > because BST does not allow equality
        if (largest && largest->val >= root->val)
            return false;
	// if root->left is valid BST, root->val is the largest
        largest = root;
        return isValidBST(root->right, largest);
    }
};
