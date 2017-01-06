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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ret;
        if (root == nullptr)
            return ret;
        deque<TreeNode *> q;
        q.push_back(nullptr);
        q.push_back(root);
        q.push_back(nullptr);
        vector<int> vec;
        while (!q.empty()) {
            root = q.front();
            if (root == nullptr) {
                q.pop_front();
                vec.clear();
                for (auto &&item : q)
                    if (item == nullptr)
                        break;
                    else
                        vec.push_back(item->val);
                if (vec.empty())
                    break;
                ret.push_back(vec);
                root = q.front();
            }
            q.pop_front();
            if (root->left)
                q.push_back(root->left);
            if (root->right)
                q.push_back(root->right);
            if (q.front() == nullptr)
                q.push_back(nullptr);
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ret;
        if (root == nullptr)
            return ret;
        queue<TreeNode *> q;
        q.push(root);
        q.push(nullptr);
        vector<int> vec;
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
        return ret;
    }
};

// Recursive solution - O(n) time complexity
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        buildRet(root, 0);
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

// Iterative solution - O(n) time and space complexity
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode *, int> > q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            auto node(q.front().first);
            auto level(q.front().second);
            q.pop();
            if (!node)
                continue;
            if (ret.size() == level)
                ret.resize(level + 1);
            ret[level].push_back(node->val);
            if (node->left)
                q.push(make_pair(node->left, level + 1));
            if (node->right)
                q.push(make_pair(node->right, level + 1));
        }
        return ret;
    }
    
private:

    vector<vector<int> > ret;
};
