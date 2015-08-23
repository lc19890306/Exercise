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
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return {};
        vector<int> ret;
        auto left(postorderTraversal(root->left));
        for (auto &&element : left)
            ret.push_back(element);
        auto right(postorderTraversal(root->right));
        for (auto &&element : right)
            ret.push_back(element);
        ret.push_back(root->val);
        return ret;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.empty() && root) {
            auto root(nodes.top());
            ret.insert(ret.begin(), root->val);
            nodes.pop();
            if (root->left)
                nodes.push(root->left);
            if (root->right)
                nodes.push(root->right);
        }
        return ret;
    }
};
