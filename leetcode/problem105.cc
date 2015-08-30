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
        if (preorder.empty() || inorder.empty())
            return nullptr;
        stack<TreeNode *> s;
        auto pre(preorder.begin());
        auto in(inorder.begin());
        TreeNode *root = new TreeNode(*pre);
	    s.push(root);
	    ++pre;
        TreeNode *node_short_of_right = nullptr;
        while (pre < preorder.end()) {
            if (!s.empty() && s.top()->val == *in) {
                node_short_of_right = s.top();
                s.pop();
                ++in;
            }
            else if (node_short_of_right != nullptr) {
                TreeNode *node = new TreeNode(*pre);
                node_short_of_right->right = node;
                node_short_of_right = nullptr;
                s.push(node);
                ++pre;
            } else {
                TreeNode *node = new TreeNode(*pre);
                s.top()->left = node;
                s.push(node);
                ++pre;
            }
        }
        return root;
    }
};
