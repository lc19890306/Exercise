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
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
      // If no overlap
        if (root == nullptr || root->end < start || end < root->start)
            return INT_MIN;
	// If [root->start, root->end] in [start, end]
        if (start <= root->start && root->end <= end)
            return root->max;
        return max(query(root->left, start, end), query(root->right, start, end));
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
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if (root == nullptr)
            return INT_MIN;
        stack<SegmentTreeNode *> s;
        s.push(root);
        auto max(INT_MIN);
        while (!s.empty()) {
            auto node(s.top());
            s.pop();
            if (start <= node->start && node->end <= end)
                max = std::max(max, node->max);
            else if (node->end < start || end < node->start)
                continue;
            else {
                s.push(node->left);
                s.push(node->right);
            }
        }
        return max;
    }
};

// Optimized iterative version
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
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if (root == nullptr)
            return INT_MIN;
        stack<SegmentTreeNode *> s;
        s.push(root);
        auto max(INT_MIN);
        while (!s.empty()) {
            auto node(s.top());
            s.pop();
            if (start <= node->start && node->end <= end)
                max = std::max(max, node->max);
            else if (node->end < start || end < node->start)
                continue;
            else {
                auto mid((node->start + node->end) >> 1);
                if (end <= mid)
                    s.push(node->left);
                else if (mid < start)
                    s.push(node->right);
                else {
                    s.push(node->left);
                    s.push(node->right);
                }
            }
        }
        return max;
    }
};
