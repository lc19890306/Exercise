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
    ListNode* swapPairs(ListNode* head) {
        if (!head)
            return head;
        ListNode dummy_head(0);
        dummy_head.next = head;
        auto behind(head), front(head), pred(&dummy_head);
        while (behind && behind->next) {
            front = behind->next;
            behind->next = front->next;
            front->next = behind;
            pred->next = front;
            pred = behind;
            behind = behind->next;
        }
        return dummy_head.next;
    }
};
