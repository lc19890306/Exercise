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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> vec;
        pathSum(root, sum, vec);
        return ret;
    }
    
private:
    void pathSum(TreeNode *root, int sum, vector<int> &vec) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            vec.push_back(root->val);
            if (sum == root->val) {
                ret.push_back(vec);
            }
            return;
        }
        vec.push_back(root->val);
        if (root->left) {
            pathSum(root->left, sum - root->val, vec);
            vec.pop_back();
        }
        if (root->right) {
            pathSum(root->right, sum - root->val, vec);
            vec.pop_back();
        }
    }
    
    vector<vector<int> > ret;
};
