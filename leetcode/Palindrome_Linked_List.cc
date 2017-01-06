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
    bool isPalindrome(ListNode* head) {
        ListNode dummy_node(0), *slow(&dummy_node), *fast(&dummy_node);
        dummy_node.next = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        ListNode *head2(reverseList(fast));
        while (head2 && head2->val == head->val) {
            head = head->next;
            head2 = head2->next;
        }
        return !head2;
    }
    
private:
    ListNode *reverseList(ListNode *head) {
        ListNode *prev(nullptr), *cur(head);
        while (cur) {
            auto succ(cur->next);
            cur->next = prev;
            prev = cur;
            cur = succ;
        }
        return prev;
    }
};
