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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr)
            return head;
        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;
        vector<ListNode *> nodes;
        auto node(dummy_head);
        while (node) {
            nodes.push_back(node);
            node = node->next;
        }
        nodes[nodes.size() - n - 1]->next = nodes[nodes.size() - n]->next;
        return dummy_head->next;
    }
};

// front pointer goes first with n steps, then front and behind pointers go together until front pointer reaches the of list, at this time behind pointer reaches target node to be deleted
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr)
            return head;
        auto front(head);
        auto behind(&head);
        while (front) {
            front = front->next;
            if (--n < 0)
                behind = &(*behind)->next;
        }
        auto to_be_deleted(*behind);
        *behind = (*behind)->next;
        delete to_be_deleted;
        return head;
    }
};

// similar to the above solution
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy_head(0), *slow(&dummy_head), *fast(&dummy_head);
        dummy_head.next = head;
        ++n;
        while (fast && n-- > 0)
            fast = fast->next;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }
	// slow is the prev of the final node to be removed for convenience
        slow->next = slow->next->next;
        return dummy_head.next;
    }
};
