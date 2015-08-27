// Too clumsy!! Ignore!!
// First run DFS to collect all nodes in the path from root to p or q
// then iterate each node on the path backwards and run DFS on each node to find q or p
// if current node is p or q, run a complete DFS on both node->left and node->right
// if current node->left is on the path, run DFS on node->right
// if current node->right is on the path, continue
// if found then this node is the lowest common ancestor
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || p == nullptr || q == nullptr)
            return root;
        deque<TreeNode *> path;
        find_path(root, p, q, path);
        auto target(path.back() == p ? q : p);
        for (auto it(path.rbegin()); it != path.rend(); ++it) {
            if (*it == path.back() && find(*it, target))
                return *it;
            if ((*it)->left == it[-1] && find((*it)->right, target))
                return *it;
        }
    }
    
private:
    void find_path(TreeNode *root, TreeNode *target1, TreeNode *target2, deque<TreeNode *> &path) {
        if (root == nullptr || target1 == nullptr || target2 == nullptr)
            return;
        if (root == target1) {
            path.push_back(target1);
            return;
        }
        if (root == target2) {
            path.push_back(target2);
            return;
        }
        path.push_back(root);
        find_path(root->left, target1, target2, path);
        if (path.back() == target1 || path.back() == target2)
            return;
        find_path(root->right, target1, target2, path);
        if (path.back() != target1 && path.back() != target2)
            path.pop_back();
        return;
    }
    
    bool find(TreeNode *root, TreeNode *target) {
        if (root == nullptr)
            return false;
        if (root == target)
            return true;
        return find(root->left, target) | find(root->right, target);
    }
};

// Run DFS on root->left and root->right, respectively
// If both left and right are not nullptr, p and q are located on each side, respectively, then root is the LCA
// Otherwise, if only left is not nullptr, p and q are must located on the left side, then the node returned by DFS is the LCA
// the same for the right
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q || root == nullptr)
            return root;
        auto left(lowestCommonAncestor(root->left, p, q));
        auto right(lowestCommonAncestor(root->right, p, q));
        return left && right ? root : left ? : right;
    }
};
