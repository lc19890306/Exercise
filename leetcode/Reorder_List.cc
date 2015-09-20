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
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;
        auto behind(head), front(head);
        while (front->next && front->next->next) {
            behind = behind->next;
            front = front->next->next;
        }
        auto head2(reverseList(behind->next));
        behind->next = nullptr;
        auto node(head);
        while (node) {
            if (node == head) {
	      // CAUTION!! move head forward FIRST!!
                head = head->next;
                node->next = head2;
            }
            else {
                head2 = head2->next;
                node->next = head;
            }
            node = node->next;
        }
    }
    
private:
    ListNode * reverseList(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *pred = nullptr;
        auto node(head);
        while (node) {
            auto succ(node->next);
            node->next = pred;
            pred = node;
            node = succ;
        }
        return pred;
    }
};
