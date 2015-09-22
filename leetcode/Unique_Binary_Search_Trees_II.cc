#include "TreeNode.hh"

#include <vector>
#include <algorithm>

using namespace std;

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
        if (n < 1)
            return {};
        return generateTrees(1, n);
    }
    
private:
    vector<TreeNode *> generateTrees(int smallest, int largest) {
        vector<TreeNode *> ret;
        if (smallest == largest) {
            ret.push_back(new TreeNode(smallest));
            return ret;
        }
        for (int i(smallest); i <= largest; ++i) {
            auto vec(generateTreesForRoot(i, largest));
            copy(vec.begin(), vec.end(), back_inserter(ret));
        }
        return ret;
    }
    
    vector<TreeNode *> generateTreesForRoot(int r, int n) {
        TreeNode *root = new TreeNode(r);
        auto left_subtrees(generateTrees(1, r - 1)), right_subtrees(generateTrees(r + 1, n));
        vector<TreeNode *> ret;
        if (left_subtrees.empty())
            left_subtrees.push_back(nullptr);
        else if (right_subtrees.empty())
            right_subtrees.push_back(nullptr);
        for (auto &&left_subtree : left_subtrees)
            for (auto &&right_subtree : right_subtrees) {
                root->left = left_subtree;
                root->right = right_subtree;
                ret.push_back(root);
            }
        return ret;
    }
};

int main() {
  Solution s;
  auto ret(s.generateTrees(3));
  return 0;
}
