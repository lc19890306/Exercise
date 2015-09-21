// WRONG but accepted solution
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root)
            return;
        queue<pair<TreeLinkNode *, int> > q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            auto pair(q.front());
            q.pop();
            if (!q.empty() && pair.second == q.front().second)
                pair.first->next = q.front().first;
            if (pair.first->left)
                q.push(make_pair(pair.first->left, pair.second + 1));
            if (pair.first->right)
                q.push(make_pair(pair.first->right, pair.second + 1));
        }
    }
};

// Non-recursive solution
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root)
            return;
	// Iterate along the left and do level order iteration
        while (root->left) {
            auto node(root);
	    // Because all the nodes on the previous level have been connected
	    // iterate along the previous level to connect all the nodes on the current level
            while (node) {
	      // connect left and right
                node->left->next = node->right;
		// connect right with next left on the right
                if (node->next)
                    node->right->next = node->next->left;
                node = node->next;
            }
            root = root->left;
        }
    }
};
