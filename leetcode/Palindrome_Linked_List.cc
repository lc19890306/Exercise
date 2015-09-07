class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next)
            return true;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        ListNode *second = reverseList(fast);
        while (second && second->val == head->val) {
            second = second->next;
            head = head->next;
        }
        slow->next = fast;
        return second == NULL;
    }
private:
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = NULL, *next = NULL;
        while (head) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};
