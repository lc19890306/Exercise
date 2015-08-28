// WRONG!!! DO NOT USE THIS VERSION!!!
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        if (root != nullptr)
            reverseInOrder(root);
        i = 0;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return i < q.size();
    }

    /** @return the next smallest number */
    int next() {
        return q[i++];
    }
    
private:
    void reverseInOrder(TreeNode *root) {
        if (root == nullptr)
            return;
        reverseInOrder(root->left);
        q.push_back(root->val);
        reverseInOrder(root->right);
    }
    
    deque<int> q;
    size_t i;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

// This is the correct version because it uses O(h) space while the above version uses O(n) space
// 
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        pushAllLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        auto node(s.top());
        s.pop();
        pushAllLeft(node->right);
        return node->val;
    }
    
private:
    void pushAllLeft(TreeNode *root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }
    
    stack<TreeNode *> s;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
