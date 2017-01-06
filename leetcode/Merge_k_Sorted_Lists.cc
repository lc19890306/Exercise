// O(nlogk) time and O(k) complexity
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy_head(0), *tail(&dummy_head);
        priority_queue<ListNode *, vector<ListNode *>, greater> q;
        for (auto &&node : lists)
            if (node)
                q.push(node);
        while (!q.empty()) {
            tail->next = q.top();
            q.pop();
            tail = tail->next;
            if (tail->next)
                q.push(tail->next);
        }
        return dummy_head.next;
    }
    
private:
    struct greater {
        bool operator()(ListNode *lhs, ListNode *rhs) {
            return lhs->val > rhs->val;
        }
    };
};
