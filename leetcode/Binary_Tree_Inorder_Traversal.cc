// Recursive version
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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return {};
        vector<int> ret;
        for (auto &&element : inorderTraversal(root->left))
            ret.push_back(element);
        ret.push_back(root->val);
        for (auto &&element : inorderTraversal(root->right))
            ret.push_back(element);
        return ret;
    }
};

// Iterative version
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<pair<TreeNode *, bool> > s;
        s.push(make_pair(root, false));
        bool visited;
        while (!s.empty()) {
            root = s.top().first;
            visited = s.top().second;
            s.pop();
            if (!root)
                continue;
            if (visited)
                ret.push_back(root->val);
            else {
                s.push(make_pair(root->right, false));
                s.push(make_pair(root, true));
                s.push(make_pair(root->left, false));
            }
        }
        return ret;
    }
};
