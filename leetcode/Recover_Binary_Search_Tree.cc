// Morris inorder traversal solution - O(n) time and O(1) space complexity
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
    void recoverTree(TreeNode* root) {
        TreeNode *cur(root), *prev(nullptr), *first(nullptr), *second(nullptr);
        while (cur) {
            if (!cur->left) {
                if (prev && prev->val > cur->val) {
                    first = first ? : prev;
                    second = cur;
                }
		// prev is set to cur only if cur has been visited
                prev = cur;
                cur = cur->right;
            }
            else {
                auto node(cur->left);
                while (node->right && node->right != cur)
                    node = node->right;
                if (!node->right) {
                    node->right = cur;
                    cur = cur->left;
                }
                else {
                    if (prev && prev->val > cur->val) {
                        first = first ? : prev;
                        second = cur;
                    }
                    node->right = nullptr;
		    // prev is set to cur only if cur has been visited
                    prev = cur;
                    cur = cur->right;
                }
            }
        }
        if (first && second)
            swap(first->val, second->val);
    }
};
