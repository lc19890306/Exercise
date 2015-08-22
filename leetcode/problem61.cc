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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
            return NULL;
        if (k == 0)
            return head;
        ListNode *cur_node = head;
        ListNode *old_tail = head;
        ListNode *new_tail = head;
        ListNode *new_head = head;
        int size(1);
        while (cur_node->next != NULL) {
            ++size;
            cur_node = cur_node->next;
        }
        old_tail = cur_node;
        k %= size;
        if (k == 0)
            return head;
        cur_node = head;
        k = size - k;
        for (int i(1); i < k; ++i)
            cur_node = cur_node->next;
        new_tail = cur_node;
        
        new_head = new_tail->next;
        new_tail->next = NULL;
        old_tail->next = head;
        return new_head;
    }
};
