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
    bool isSymmetric(TreeNode* root) {
        auto copy(copyTree(root));
        auto inverted_tree(invertTree(copy));
        return isSameTree(root, inverted_tree);
    }
    
private:
    TreeNode *copyTree(TreeNode *root) {
        if (root == nullptr)
            return root;
        TreeNode *copy = new TreeNode(root->val);
        copy->left = copyTree(root->left);
        copy->right = copyTree(root->right);
        return copy;
    }
    
    TreeNode *&invertTree(TreeNode *&root) {
        if (root == nullptr)
            return root;
        swap(invertTree(root->left), invertTree(root->right));
        return root;
    }
    
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && q || p && !q)
            return false;
        if (!p && !q)
            return true;
        if (p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        return false;
    }
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return isInverted(root->left, root->right);
    }
    
private:
    bool isInverted(TreeNode *p, TreeNode *q) {
        if (!p && q || p && !q)
            return false;
        if (!p && !q)
            return true;
        if (p->val != q->val)
            return false;
        return isInverted(p->left, q->right) && isInverted(p->right, q->left);
    }
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        deque<TreeNode *> q;
        q.push_front(root->left);
        q.push_back(root->right);
        while (!q.empty()) {
            auto left(q.front());
            q.pop_front();
            auto right(q.back());
            q.pop_back();
            if (!left && right || left && !right)
                return false;
            if (left && right) {
                if (left->val != right->val)
                    return false;
                else {
                    q.push_front(left->right);
                    q.push_front(left->left);
                    q.push_back(right->left);
                    q.push_back(right->right);
                }
            }
        }
        return true;
    }
};
