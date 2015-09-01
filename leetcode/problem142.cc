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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr)
            return nullptr;
        auto fast(head), slow(head);
	// Make sure fast->next and fast->next->next are not nullptr in order not to introduce runtime error
	// also, if either of them become nullptr, no cycle exists in the linked list
	// in each iteration, slow move one step forward while fast move two steps forward so that fast will finally catch up with slow if cycle exists
	// at that time, slow should have moved s steps while fast should have moved 2 * s steps
	// assume moving from the node where cycle begins to the node where slow and fast meet need k steps
	// then, moving from head to the node where cycle begins requires (s - k) steps and
	// moving from the node where slow and fast meet back to the node where cycle begins need (2 * s - s - k) = (s - k) steps (the cycle's length is actually s)
	// therefore, slow can move (s - k) more steps to go back to the node where cycle begins
	// likewise, head can move (s - k) steps to reach the node where cycle begins
	// SO we just return the node where head and slow meet
	// although fast and slow will definitely meet in some place
	// we cannot use fast == slow as the break condition because
	// both fast and slow point to head at the very beginning
	// to solve this problem, we use fast->next == slow as the break condition
	// because this is the last but one iteration before they meet
        while (fast->next != nullptr && fast->next->next != nullptr && fast->next != slow) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast->next == nullptr || fast->next->next == nullptr)
            return nullptr;
	// since fast and slow still need an iteration before meeting
	// we let slow move one step forward to make it reach the node where it should meet with fast
        slow = slow->next;
        while (head != slow) {
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};
