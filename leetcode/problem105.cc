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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (auto it(inorder.begin()); it != inorder.end(); ++it)
            inorder_map[*it] = it;
        return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    
private:
    typedef vector<int>::iterator Iterator;
    TreeNode *buildTree(Iterator pre_first, Iterator pre_last, Iterator in_first, Iterator in_last) {
        if (pre_first == pre_last || in_first == in_last)
            return nullptr;
        TreeNode *ret = new TreeNode(*pre_first);
        auto root(inorder_map[ret->val]);
        ret->left = buildTree(pre_first + 1, pre_first + 1 + distance(in_first, root), in_first, root);
        ret->right = buildTree(pre_first + 1 + distance(in_first, root), pre_last, root + 1, in_last);
        return ret;
    }
    unordered_map<int, Iterator> inorder_map;
};
