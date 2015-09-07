// Remember, it is necessary to recalculate the postorder iterators (not only inorder iterators) in order to find suitable range for inorder
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
    
private:
    typedef vector<int>::iterator Iterator;
    TreeNode *buildTree(Iterator in_first, Iterator in_last, Iterator post_first, Iterator post_last) {
        if (in_first == in_last || post_first == post_last)
            return nullptr;
        TreeNode *ret = new TreeNode(post_last[-1]);
        auto root(find(in_first, in_last, ret->val));
        ret->left = buildTree(in_first, root, post_first, post_last - distance(root, in_last));
        ret->right = buildTree(root + 1, in_last, post_first + distance(in_first, root), post_last - 1);
        return ret;
    }
};

// Use hash_map to store inorder array and corresponding iterators to expedite locating (finding) target root iterator
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        inorder_map.clear();
        for (auto it(inorder.begin()); it != inorder.end(); ++it)
            inorder_map[*it] = it;
        return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
    
private:
    typedef vector<int>::iterator Iterator;
    TreeNode *buildTree(Iterator in_first, Iterator in_last, Iterator post_first, Iterator post_last) {
        if (in_first == in_last || post_first == post_last)
            return nullptr;
        TreeNode *ret = new TreeNode(post_last[-1]);
        auto root(inorder_map.find(ret->val)->second);
        ret->left = buildTree(in_first, root, post_first, post_last - distance(root, in_last));
        ret->right = buildTree(root + 1, in_last, post_first + distance(in_first, root), post_last - 1);
        return ret;
    }
    unordered_map<int, Iterator> inorder_map;
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty())
            return nullptr;
        stack<TreeNode *> s;
        auto in(inorder.rbegin());
        auto post(postorder.rbegin());
        TreeNode *root = new TreeNode(*post);
        s.push(root);
        ++post;
        TreeNode *node_short_of_left = nullptr;
        while (post < postorder.rend()) {
            if (!s.empty() && s.top()->val == *in) {
                node_short_of_left = s.top();
                s.pop();
                ++in;
            }
            else if (node_short_of_left != nullptr) {
                TreeNode *node = new TreeNode(*post);
                node_short_of_left->left = node;
                node_short_of_left = nullptr;
                s.push(node);
                ++post;
            }
            else {
                TreeNode *node = new TreeNode(*post);
                s.top()->right = node;
                s.push(node);
                ++post;
            }
        }
        return root;
    }
};
