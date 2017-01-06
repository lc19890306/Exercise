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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        int countA(0), countB(0);
        auto nodeA(headA), nodeB(headB);
        while (nodeA) {
            nodeA = nodeA->next;
            ++countA;
        }
        while (nodeB) {
            nodeB = nodeB->next;
            ++countB;
        }
        auto shorter(headA), longer(headB);
        if (countA > countB)
            swap(shorter, longer);
        int diff(abs(countA - countB));
        while (diff-- > 0)
            longer = longer->next;
        while (shorter != longer) {
            shorter = shorter->next;
            longer = longer->next;
        }
        return shorter;
    }
};

// Best solution
// Assume B is longer than A, let node1 and node2 iterate A and B until node1 reaches nullptr
// then let node1 iterates B, which makes them "align" the same when node2 reaches nullptr
// then node1 and node2 will reach the same colliding node or nullptr (another king of colliding node) and return it
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto node1(headA), node2(headB);
        while (node1 != node2) {
	  // WRONG!! node1 = node1->next ? : headB
	  // because nullptr should be treated as an intersection so nullptr should be considered as a node as well as regular node
	  // a1 a2 NL b1 b2 b3 NL
	  // b1 b2 b3 NL a1 a2 NL
	  // OTHERWISE
	  // a1 a2 b1 b2 b3 ...
	  // b1 b2 b3 a1 a2 ...
	  // TLE!!!!
            node1 = node1 ? node1->next : headB;
            node2 = node2 ? node2->next : headA;
        }
        return node1;
    }
};
