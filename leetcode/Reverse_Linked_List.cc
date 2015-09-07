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
    ListNode* reverseList(ListNode* head) {
        ListNode *node = head;
        ListNode *pred = nullptr;
        while (node != nullptr) {
            auto succ(node->next);
            node->next = pred;
            pred = node;
            node = succ;
        }
        return pred;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *node = head->next;
        head->next = nullptr;
        auto ret(reverseList(node));
        node->next = head;
        return ret;
    }
};
