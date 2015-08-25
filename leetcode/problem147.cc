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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr)
            return head;
        auto prev_i(head);
        auto i(head->next);
        ListNode *prev_head = new ListNode(INT_MIN);
        prev_head->next = head;
        auto prev_j(prev_head);
        auto j(prev_head->next);
        while (i) {
            // Speedup trick: if current i->val < previously inserted i->val, 
            // we can directly search from the place where we previously inserted i (i->next actually)
            if (prev_j->val > i->val) { // prev_j equals the previously inserted i
                prev_j = prev_head;
                j = prev_j->next;
            }
            while (j != i && j->val <= i->val) {
                prev_j = j;
                j = j->next;
            }
            if (j != i) {
                prev_i->next = i->next;
                prev_j->next = i;
                i->next = j;
                prev_j = i;
                i = prev_i->next;
            }
            else {
                prev_i = i;
                i = i->next;
            }
        }
        return prev_head->next;
    }
};
