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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return head;
        ListNode *node = head;
        ListNode *tail = head;
        while (node->next != NULL) {
            if (node->val == val)
                *node = *(node->next);
            else {
                tail = node;
                node = node->next;
            }
        }
        if (tail->val == val)
            return NULL;
        else if (node->val == val)
            tail->next = NULL;
        return head;
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)     return NULL;
        if (head->val == val) return removeElements(head->next,val);
        head->next = removeElements(head->next,val);
        return head;
    }
};
