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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums.begin(), nums.end());
    }
    
private:
    typedef vector<int>::iterator Iterator;
    
    TreeNode *sortedArrayToBST(Iterator first, Iterator last) {
        if (first == last)
            return nullptr;
        auto count(distance(first, last));
        auto mid(first + (count >> 1));
        TreeNode *node = new TreeNode(*mid);
        node->left = sortedArrayToBST(first, mid);
        node->right = sortedArrayToBST(mid + 1, last);
        return node;
    }
};
