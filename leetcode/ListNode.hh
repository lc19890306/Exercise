#ifndef LISTNODE_HH
#define LISTNODE_HH

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };

#endif	// LISTNODE_HH
