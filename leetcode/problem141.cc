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
    bool hasCycle(ListNode *head) {
      // head->next and head will be used so we must ensure they are not nullptr so as not to introduce runtime error
      // also, if either of them is nullptr, no cycle exists in the linked list
        if (head == nullptr || head->next == nullptr)
            return false;
	// head is actually an address, we hope to check if the content "next" in *head would be equal to the address "head" itself
	// therefore, we have to change the address head by moving it forward and
	// also, change the content by moving it backward
	// in order to make the content "next" and the address "head" MEET in some place
        while (head != nullptr && head->next != head && head->next != nullptr) {
            *head = *(head->next);
            head = head->next;
        }
        return head != nullptr && head->next == head;
    }
};
