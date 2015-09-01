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
        if (head == nullptr)
            return head;
        auto list(&head);
        while ((*list)->next) {
            if ((*list)->val == (*list)->next->val)
                *list = (*list)->next;
            else
                list = &(*list)->next;
        }
        return head;
    }
};

// Faster~~~~~~~~~~~
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return head;
        auto node(head);
        while (node->next) {
            if (node->val == node->next->val)
                node->next = node->next->next;
            else
                node = node->next;
        }
        return head;
    }
};
