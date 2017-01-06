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
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        if (!isBalanced(root->left) || !isBalanced(root->right))
            return false;
        auto diff(height(root->left) - height(root->right));
        if (diff < -1 || diff > 1)
            return false;
        return true;
    }
    
private:
    int height(TreeNode *root) {
        if (!root)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
};

// Recursive DFS solution + cache each node's height
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
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        if (!isBalanced(root->left) || !isBalanced(root->right))
            return false;
        auto diff(height(root->left) - height(root->right));
        if (diff < -1 || diff > 1)
            return false;
        return true;
    }
    
private:
    int height(TreeNode *root) {
        if (!root)
            return 0;
        if (hash_map.find(root) != hash_map.end())
            return hash_map[root];
        auto h(max(height(root->left), height(root->right)) + 1);
        hash_map[root] = h;
        return h;
    }
    
    unordered_map<TreeNode *, int> hash_map;
};

// Recursive DFS solution - no additional recursion for height computation
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
    bool isBalanced(TreeNode* root) {
        int height(0);
        return isBalanced(root, height);
    }
    
private:
    bool isBalanced(TreeNode *root, int &height) {
        if (!root)
            return true;
        ++height;
        int left_height(0), right_height(0);
        if (!isBalanced(root->left, left_height) || !isBalanced(root->right, right_height))
            return false;
        auto diff(left_height - right_height);
        if (diff < -1 || diff > 1)
            return false;
        height += max(left_height, right_height);
        return true;
    }
};

// the same as the above solution
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
    bool isBalanced(TreeNode* root) {
        int depth(0);
        return isBalanced(root, depth);
    }
    
private:
    bool isBalanced(TreeNode *root, int &depth) {
        if (!root)
            return true;
        ++depth;
        int left_depth(0);
        if (!isBalanced(root->left, left_depth))
            return false;
        int right_depth(0);
        if (!isBalanced(root->right, right_depth))
            return false;
        if (abs(left_depth - right_depth) > 1)
            return false;
        depth += max(left_depth, right_depth);
        return true;
    }
};
