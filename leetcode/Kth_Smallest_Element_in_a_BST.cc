// Recursive inorder traversal solution - O(k) time complexity
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
    int kthSmallest(TreeNode* root, int k) {
        DFS(root, k);
        return ret;
    }
    
private:
    void DFS(TreeNode *root, int &k) {
        if (!root)
            return;
        DFS(root->left, k);
        if (!k)
            return;
        --k;
        if (!k) {
            ret = root->val;
            return;
        }
        DFS(root->right, k);
        if (!k)
            return;
    }
    
    int ret;
};

// If TreeNode can be modified, add a count field to count all the nodes on the tree with a root of current node
// each insert or delete only takes O(logn) time to update the count field of each node visited
// O(h) complexity where h is the height of the tree
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
    int kthSmallest(TreeNode* root, int k) {
        TreeNodeWithCount *node = buildTree(root);
        return kthSmallest(node, k);
    }
    
private:
    struct TreeNodeWithCount {
        int val;
        int count;
        TreeNodeWithCount *left;
        TreeNodeWithCount *right;
        TreeNodeWithCount(int x) : val(x), count(1), left(nullptr), right(nullptr) {}
    };
    
    TreeNodeWithCount * buildTree(TreeNode *root) {
        if (!root)
            return nullptr;
        TreeNodeWithCount *node = new TreeNodeWithCount(root->val);
        node->left = buildTree(root->left);
        node->right = buildTree(root->right);
        if (node->left)
            node->count += node->left->count;
        if (node->right)
            node->count += node->right->count;
        return node;
    }

    int kthSmallest(TreeNodeWithCount *root, int k) {
        if (root->left) {
            if (root->left->count >= k)
                return kthSmallest(root->left, k);
            if (root->left->count == k - 1)
                return root->val;
            return kthSmallest(root->right, k - 1 - root->left->count);
        }
        else {
            if (k == 1)
                return root->val;
            return kthSmallest(root->right, k - 1);
        }
    }
};
