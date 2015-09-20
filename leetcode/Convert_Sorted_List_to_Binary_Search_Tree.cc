// O(nlogn) time complexity
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return nullptr;
        auto behind(head), front(head), pred(head);
        while(front && front->next) {
            pred = behind;
            behind = behind->next;
            front = front->next->next;
        }
        TreeNode *ret = new TreeNode(behind->val);
        if (pred != behind) {
            pred->next = nullptr;
            ret->left = sortedListToBST(head);
        }
        ret->right = sortedListToBST(behind->next);
        return ret;
    }
};
