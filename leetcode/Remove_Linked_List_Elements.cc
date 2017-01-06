// Best solution
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy_head(0), *prev(&dummy_head);
        dummy_head.next = head;
        while (prev->next) {
            if (prev->next->val == val)
                prev->next = prev->next->next;
            else
                prev = prev->next;
        }
        return dummy_head.next;
    }
};

#include <cstdlib>

  // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return head;
        ListNode *node = head;
        ListNode *tail = head;
        while (node->next != NULL) {
            if (node->val == val)
                *node = *(node->next);
            else {
                tail = node;
                node = node->next;
            }
        }
        if (tail->val == val)
            return NULL;
        else if (node->val == val)
            tail->next = NULL;
        return head;
    }
};

// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
//         if (head == NULL)     return NULL;
//         if (head->val == val) return removeElements(head->next,val);
//         head->next = removeElements(head->next,val);
//         return head;
//     }
// };

// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
//     ListNode **list = &head;

//     while (*list != nullptr)
//     {
//         if ((*list)->val == val)
//         {
//     	  auto temp(*list);
//     	  auto temp2(&(*list)->next);
//             *list = (*list)->next;
//     	    // delete *temp;
//         }
//         else
//         {
//             list = &(*list)->next;
//         }
//     }

//     return head;
//     }
// };

int main() {
  ListNode * x;
  ListNode *node = new ListNode(0);
  node->next = new ListNode(1);
  node->next->next = new ListNode(2);
  node->next->next->next = new ListNode(0);
  node->next->next->next->next = new ListNode(1);
  Solution s;
  auto res = s.removeElements(node, 0);
  return 0;
}
