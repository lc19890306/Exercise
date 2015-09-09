// Recursive version1
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
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right != nullptr)
            return minDepth(root->right) + 1;
        if (root->left != nullptr && root->right == nullptr)
            return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

// Recursive version2 - maybe faster but not that straightforward
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
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr)
            return minDepth(root->right) + 1;
        if (root->right == nullptr)
            return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

// Iterative version - the same as recursive version1
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
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        queue<pair<TreeNode *, int> > q;
        q.push(make_pair(root, 1));
        while (!q.empty()) {
            auto node(q.front());
            q.pop();
            if (node.first->left == nullptr && node.first->right == nullptr)
                return node.second;
            else if (node.first->left == nullptr && node.first->right != nullptr)
                q.push(make_pair(node.first->right, node.second + 1));
            else if (node.first->left != nullptr && node.first->right == nullptr)
                q.push(make_pair(node.first->left, node.second + 1));
            else {
                q.push(make_pair(node.first->left, node.second + 1));
                q.push(make_pair(node.first->right, node.second + 1));
            }
        }
    }
};
