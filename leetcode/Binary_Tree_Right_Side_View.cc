// Recursive DFS solution
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
    vector<int> rightSideView(TreeNode* root) {
        rightSideView(root, 0);
        return nodes;
    }
    
private:
    void rightSideView(TreeNode *root, int level) {
        if (!root)
            return;
        if (level == nodes.size())
            nodes.push_back(root->val);
        rightSideView(root->right, level + 1);
        rightSideView(root->left, level + 1);
    }
    
    vector<int> nodes;
};

// BFS solution
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (!root)
            return ret;
        queue<pair<TreeNode *, int> > q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            auto pair(q.front());
            q.pop();
            if (pair.second == ret.size())
                ret.push_back(pair.first->val);
            if (pair.first->right)
                q.push(make_pair(pair.first->right, pair.second + 1));
            if (pair.first->left)
                q.push(make_pair(pair.first->left, pair.second + 1));
        }
        return ret;
    }
};
