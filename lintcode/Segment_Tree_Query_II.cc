// Recursive version
/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The count number in the interval [start, end] 
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if (root == nullptr || root->end < start || end < root->start)
            return 0;
        if (start <= root->start && root->end <= end)
            return root->count;
        return query(root->left, start, end) + query(root->right, start, end);
    }
};

// Iterative version
/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The count number in the interval [start, end] 
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if (root == nullptr)
            return 0;
        stack<SegmentTreeNode *> s;
        s.push(root);
        auto ret(0);
        while (!s.empty()) {
            auto node(s.top());
            s.pop();
            if (node->end < start || end < node->start)
                continue;
            if (start <= node->start && node->end <= end)
                ret += node->count;
            else {
                    s.push(node->left);
                    s.push(node->right);
            }
        }
        return ret;
    }
};
