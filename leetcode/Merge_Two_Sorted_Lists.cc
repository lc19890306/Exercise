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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy_head(0);
        auto node(&dummy_head);
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                node->next = l1;
                l1 = l1->next;
            }
            else {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        node->next = nullptr == l1 ? l2 : l1;
        return dummy_head.next;
    }
};
