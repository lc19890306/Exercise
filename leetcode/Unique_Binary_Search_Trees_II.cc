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
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
    
private:
    vector<TreeNode *> generateTrees(int smallest, int largest) {
        vector<TreeNode *> ret;
        if (smallest > largest) {
            ret.push_back(nullptr);
            return ret;
        }
        for (int i(smallest); i <= largest; ++i) {
            auto left_subtrees(generateTrees(smallest, i - 1));
            auto right_subtrees(generateTrees(i + 1, largest));
            for (auto &&left_subtree : left_subtrees)
                for (auto &&right_subtree : right_subtrees) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left_subtree;
                    root->right = right_subtree;
                    ret.push_back(root);
                }
        }
        return ret;
    }
};
