/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy_head(0);
        dummy_head.next = head;
        auto pred(&dummy_head), node(head);
        while (node) {
            auto val(node->val);
            if (node->next && node->next->val == val) {
                while (node && node->val == val)
                    node = node->next;
                pred->next = node;
                continue;
            }
            pred = node;
            node = node->next;
        }
        return dummy_head.next;
    }
};
