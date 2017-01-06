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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        buildRet(root, 0);
        reverse(ret.begin(), ret.end());
        return ret;
    }
    
private:
    void buildRet(TreeNode *root, const int &level) {
        if (root == nullptr)
            return;
        if (ret.size() == level)
            ret.resize(level + 1);
        ret[level].push_back(root->val);
        buildRet(root->left, level + 1);
        buildRet(root->right, level + 1);
        return;
    }
    vector<vector<int> > ret;
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ret;
        if (root == nullptr)
            return ret;
        queue<TreeNode *> q;
        vector<int> vec;
        q.push(root);
        q.push(nullptr);
        while (!q.empty()) {
            root = q.front();
            q.pop();
            if (root == nullptr) {
                ret.push_back(vec);
                vec.clear();
                if (!q.empty())
                    q.push(nullptr);
            }
            else {
                vec.push_back(root->val);
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

// Iterative solution
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ret;
        queue<pair<TreeNode *, int> > q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            auto node(q.front().first);
            auto level(q.front().second);
            q.pop();
            if (!node)
                continue;
            if (level == ret.size())
                ret.resize(level + 1);
            ret[level].push_back(node->val);
            q.push(make_pair(node->left, level + 1));
            q.push(make_pair(node->right, level + 1));
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
