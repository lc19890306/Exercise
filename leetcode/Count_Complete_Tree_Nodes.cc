// Binary search solution - O((logn)^2) time complexity
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
    int countNodes(TreeNode* root) {
        height = 0;
        auto node(root);
        while (node) {
            node = node->left;
            ++height;
        }
        if (height < 2)
            return height;
        auto left(1 << (height - 2)), right((left << 1) - 1);
        return countNodes(root, left, right);
    }
    
private:
    int countNodes(TreeNode *root, int left, int right) {
        auto mid((left + right) >> 1);
        auto node(root);
        auto mask(1 << (height - 3));
        while (mask > 0) {
            if (mid & mask)
                node = node->right;
            else
                node = node->left;
            mask >>= 1;
        }
        if (left == right) {
            if (!node->left)
                return (mid << 1) - 1;
            return node->right ? (mid << 1) + 1 : (mid << 1);
        }
        if (!node->left && !node->right)
            return countNodes(root, left, mid - 1);
        else if (node->left && node->right)
            return countNodes(root, mid + 1, right);
        else
            return (mid << 1);
    }
    
    int height;
};

// Binary search solution - O((logn)^2) time complexity
// 1. move leftwards all the way to the end to find the height of the tree
// 2. find the height of the right subtree
// 3. if the height of the right subtree is less than that of the entire tree, search the left subtree
// 4. otherwise search its right subtree and increment ret
// 5. in each iteration, double ret
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
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int height(0);
        auto node(root);
        while (node) {
            node = node->left;
            ++height;
        }
        int ret(1);
        node = root;
        while (--height) {
            ret <<= 1;
            auto temp(node);
            node = temp->right;
            auto right_height(0);
            while (node) {
                node = node->left;
                ++right_height;
            }
            if (height > right_height)
                node = temp->left;
            else {
                ret |= 1;	// ++ret;
                node = temp->right;
            }
        }
        return ret;
    }
};
