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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;
        else if (p == nullptr || q == nullptr)
            return root;
        else {
            auto smaller(min(p->val, q->val));
            auto larger(max(p->val, q->val));
	    // should be <= rather than < because either smaller or larger can equal to root->val
            if (smaller <= root->val && root->val <= larger)
                return root;
            else if (root->val < smaller)
                return lowestCommonAncestor(root->right, p, q);
            else
                return lowestCommonAncestor(root->left, p, q);
        }
    }
};
