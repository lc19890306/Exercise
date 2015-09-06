// Recursive version
/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end) {
 *         this->start = start, this->end = end;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(int start, int end) {
        // write your code here
        if (start > end)
            return nullptr;
        SegmentTreeNode *node = new SegmentTreeNode(start, end);
        if (start == end)
            return node;
        auto mid((start + end) >> 1);
        node->left = build(start, mid);
        node->right = build(mid + 1, end);
        return node;
    }
};

// Iterative version
/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end) {
 *         this->start = start, this->end = end;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(int start, int end) {
        // write your code here
        if (start > end)
            return nullptr;
        stack<SegmentTreeNode *> s;
        SegmentTreeNode *root = new SegmentTreeNode(start, end);
        s.push(root);
        while (!s.empty()) {
            auto node(s.top());
            s.pop();
            if (node->start < node->end) {
                auto mid((node->start + node->end) >> 1);
                node->left = new SegmentTreeNode(node->start, mid);
                s.push(node->left);
                node->right = new SegmentTreeNode(mid + 1, node->end);
                s.push(node->right);
            }
        }
        return root;
    }
};
