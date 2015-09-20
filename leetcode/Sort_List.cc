// Merge sort
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        auto behind(head), front(head);
        while (front->next && front->next->next) {
            behind = behind->next;
            front = front->next->next;
        }
        auto tail(behind);
        behind = behind->next;
        tail->next = nullptr;
        return mergeList(sortList(head), sortList(behind));
    }
    
private:
    ListNode *mergeList(ListNode *p1, ListNode *p2) {
        if (!p1)
            return p2;
        if (!p2)
            return p1;
        ListNode dummy_head(0), *tail(&dummy_head);
        while (p1 && p2) {
            if (p1->val < p2->val) {
                tail->next = p1;
                p1 = p1->next;
            }
            else {
                tail->next = p2;
                p2 = p2->next;
            }
            tail = tail->next;
        }
        tail->next = p1 ? p1 : p2;
        return dummy_head.next;
    }
};
