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
        while (root) {
            auto node(root);
            TreeLinkNode *temp = nullptr;
            while (node) {
	      // if temp is not nullptr, connect temp with current left or right if either one of them is not nullptr
                if (temp) {
                    temp->next = node->left ? node->left : node->right;
		    // if succesfully connected move temp forward
                    if (temp->next)
                        temp = temp->next;
                }
		// if both left and right are not nullptr, connect them and move temp forward
                if (node->left && node->right) {
                    node->left->next = node->right;
                    temp = node->right;
                }
		// if temp is still a nullptr, assign left or right to temp
                if (!temp)
                    temp = node->right ? node->right : node->left;
		// check next node
                node = node->next;
            }
	    // move to the next available root
            if (root->left)
                root = root->left;
            else if (root->right)
                root = root->right;
            else
                root = root->next;
        }
    }
};
