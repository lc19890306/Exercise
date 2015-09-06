// Recursive version
/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, index, value: The root of segment tree and 
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    void modify(SegmentTreeNode *root, int index, int value) {
        // write your code here
        if (root == nullptr || root->end < index || index < root->start)
            return;
        if (root->start == index && root->end == index) {
            root->max = value;
            return;
        }
        auto mid((root->start + root->end) >> 1);
        if (index <= mid)
            modify(root->left, index, value);
        else
            modify(root->right, index, value);
        root->max = max(root->left->max, root->right->max);
    }
};

// Iterative version
/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, index, value: The root of segment tree and 
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    void modify(SegmentTreeNode *root, int index, int value) {
        // write your code here
        if (root == nullptr)
            return;
        stack<pair<SegmentTreeNode *, bool> > s;
        s.push(make_pair(root, false));
        while (!s.empty()) {
            auto node(s.top());
            if (node.first->end < index || index < node.first->start)
                continue;
            if (node.first->start == index && node.first->end == index) {
                node.first->max = value;
                s.pop();
            }
            else {
                if (node.second) {
                    node.first->max = max(node.first->left->max, node.first->right->max);
                    s.pop();
                    continue;
                }
                s.top().second = true;
                auto mid((node.first->start + node.first->end) >> 1);
                if (index <= mid)
                    s.push(make_pair(node.first->left, false));
                else
                    s.push(make_pair(node.first->right, false));
            }
        }
    }
};
