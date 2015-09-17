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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy_head(0);
        dummy_head.next = head;
        auto begin(head), end(&dummy_head), node(&dummy_head), pred(&dummy_head);
        int i(0);
        while (node) {
            if (m == i)
                begin = node;
            if (n == i) {
                end = node;
                node = node->next;
                end->next = nullptr;
                break;
            }
            ++i;
            if (m == i)
                pred = node;
            node = node->next;
        }
        auto ret(reverseList(begin));
        begin->next = node;
        pred->next = ret;
        return dummy_head.next;
    }
    
private:
    ListNode *reverseList(ListNode *head) {
        if (nullptr == head || nullptr == head->next)
            return head;
        auto node(head->next);
        head->next = nullptr;
        auto ret(reverseList(node));
        node->next = head;
        return ret;
    }
};

// Almost the same as the above version
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy_head(0);
        dummy_head.next = head;
        auto begin(head), end(&dummy_head), node(&dummy_head), pred(&dummy_head);
        int i(0);
        while (node) {
            if (m == i)
                begin = node;
            if (n == i) {
                end = node;
                node = node->next;
                end->next = nullptr;
                break;
            }
            ++i;
            if (m == i)
                pred = node;
            node = node->next;
        }
        auto ret(reverseList(begin));
        begin->next = node;
        pred->next = ret;
        return dummy_head.next;
    }
    
private:
    ListNode *reverseList(ListNode *head) {
        ListNode *pred = nullptr;
        auto node(head);
        while (node) {
            auto succ(node->next);
            node->next = pred;
            pred = node;
            node = succ;
        }
        return pred;
    }
};

// 1->2->3->4->5
// add dummy_head: 0->1->2->3->4->5
// find predecesor before 2: 1
// pred: 1; begin: pred->next 2; node: begin->next 3;
// begin points to node->next
// node points to pred->next
// pred points to node
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy_head(0);
        dummy_head.next = head;
        auto pred(&dummy_head);
        n -= m;
        while (--m > 0)
            pred = pred->next;
        auto begin(pred->next);
        while (n-- > 0) {
            auto node(begin->next);
            begin->next = node->next;
            node->next = pred->next;
            pred->next = node;
        }
        return dummy_head.next;        
    }
};
