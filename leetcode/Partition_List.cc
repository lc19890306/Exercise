// Standard solution - find a large node first and then find a small node after that
// move the small node to the front of the large node
// iteratively
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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr)
            return nullptr;
        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;
        auto small(dummy_head), large(dummy_head);
        while (large->next && large->next->val < x)
            large = large->next;
        if (large->next != nullptr)
            small = large->next;
        while (large->next && small->next) {
            while (large->next != nullptr && large->next->val < x)
                large = large->next;
            while (small->next != nullptr && small->next->val >= x)
                small = small->next;
            if (large->next != nullptr && small->next != nullptr) {
                auto temp(large->next);
                large->next = small->next;
                small->next = small->next->next;
                large->next->next = temp;
            }
        }
        return dummy_head->next;
    }
};

// Best solution for this problem
// scan the entire list and divide them into two lists, the smallers and the largers
// then reconnect these two lists
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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr)
            return nullptr;
        ListNode small_head(0), large_head(0);
        auto small(&small_head), large(&large_head);
        while (head) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            }
            else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        small->next = large_head.next;
        large->next = nullptr;
        return small_head.next;
    }
};
