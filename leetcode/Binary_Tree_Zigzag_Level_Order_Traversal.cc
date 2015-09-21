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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ret;
        if (!root)
            return ret;
        stack<pair<TreeNode *, int> > odd_stack, even_stack;
        even_stack.push(make_pair(root, 0));
        bool odd_flag(false);
        while (!odd_stack.empty() || !even_stack.empty()) {
            std::pair<TreeNode *, int> pair;
            if (odd_flag) {
                pair = odd_stack.top();
                odd_stack.pop();
                if (odd_stack.empty())
                    odd_flag = false;
            }
            else {
                pair = even_stack.top();
                even_stack.pop();
                if (even_stack.empty())
                    odd_flag = true;
            }
            if (ret.size() == pair.second)
                ret.resize(pair.second + 1);
            ret[pair.second].push_back(pair.first->val);
            if (pair.second & 1) {
                if (pair.first->right)
                    even_stack.push(make_pair(pair.first->right, pair.second + 1));
                if (pair.first->left)
                    even_stack.push(make_pair(pair.first->left, pair.second + 1));
            }
            else {
                if (pair.first->left)
                    odd_stack.push(make_pair(pair.first->left, pair.second + 1));
                if (pair.first->right)
                    odd_stack.push(make_pair(pair.first->right, pair.second + 1));
            }
        }
        return ret;
    }
};
