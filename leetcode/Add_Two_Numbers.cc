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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry(0);
        ListNode *l = new ListNode(0);
        ListNode *node = l;
        while (l1 != nullptr || l2 != nullptr) {
            int sum(carry);
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            node->next = new ListNode(sum % 10);
            node = node->next;
        }
        if (carry != 0)
            node->next = new ListNode(carry);
        return l->next;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *it = NULL;
        ListNode *ret = NULL;
        int carry(0);
        bool set_head(false);
        while (l1 != NULL && l2 != NULL) {
            auto val(l1->val + l2->val + carry);
            if (it == NULL)
                it = new ListNode(val % 10);
            else {
                it->next = new ListNode(val % 10);
                it = it->next;
            }
            if (!set_head) {
                ret = it;
                set_head = true;
            }
            carry = val / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if (l1 == NULL && l2 == NULL) {
            if (carry != 0) {
                if (it == NULL)
                    it = new ListNode(carry);
                else {
                    it->next = new ListNode(carry);
                    it = it->next;
                }
                if (!set_head) {
                    ret = it;
                    set_head = true;
                }
            }
            return ret;
        }
        else if (l1 == NULL) {
            while (l2 != NULL && carry != 0) {
                auto val(l2->val + carry);
                if (it == NULL)
                    it = new ListNode(val % 10);
                else {
                    it->next = new ListNode(val % 10);
                    it = it->next;
                }
                if (!set_head) {
                    ret = it;
                    set_head = true;
                }
                carry = val / 10;
                l2 = l2->next;
            }
            if (l2 == NULL) {
                if (carry != 0)
                    it->next = new ListNode(carry);
                return ret;
            }
            if (carry == 0) {
                if (l2 != NULL)
                    it->next = l2;
                return ret;
            }
        }
        else {
            while (l1 != NULL && carry != 0) {
                auto val(l1->val + carry);
                if (it == NULL)
                    it = new ListNode(val % 10);
                else {
                    it->next = new ListNode(val % 10);
                    it = it->next;
                }
                if (!set_head) {
                    ret = it;
                    set_head = true;
                }
                carry = val / 10;
                l1 = l1->next;
            }
            if (l1 == NULL) {
                if (carry != 0)
                    it->next = new ListNode(carry);
                return ret;
            }
            if (carry == 0) {
                if (l1 != NULL)
                    it->next = l1;
                return ret;
            }
        }
    }
};
