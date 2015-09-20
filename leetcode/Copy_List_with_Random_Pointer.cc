// hashmap version
// Treat the linked list as a binary tree
// use hashmap to avoid duplicated node creation
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
            return head;
        auto it(hash_map.find(head));
        if (it != hash_map.end())
            return it->second;
        RandomListNode *ret = new RandomListNode(head->label);
        hash_map.insert({head, ret});
        ret->next = copyRandomList(head->next);
        ret->random = copyRandomList(head->random);
        return ret;
    }

private:
    unordered_map<RandomListNode *, RandomListNode *> hash_map;
};
