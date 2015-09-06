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
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        // write your code here
        if (A.empty())
            return nullptr;
        return build(0, A.size() - 1, A);
    }
    
private:
    SegmentTreeNode * build(int start, int end, vector<int> &A) {
        if (start > end)
            return nullptr;
        if (start == end)
            return new SegmentTreeNode(start, end, A[start]);
        auto mid((start + end) >> 1);
        auto left(build(start, mid, A));
        auto right(build(mid + 1, end, A));
        SegmentTreeNode * root = new SegmentTreeNode(start, end, max(left->max, right->max));
        root->left = left;
        root->right = right;
        return root;
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
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        // write your code here
        if (A.empty())
            return nullptr;
        stack<SegmentTreeNode *> s;
        SegmentTreeNode *root = new SegmentTreeNode(0, A.size() - 1, 0);
        s.push(root);
        while (!s.empty()) {
            auto node(s.top());
            if (node->start == node->end) {
                node->max = A[node->start];
                s.pop();
            }
            else if (node->start < node->end) {
                if (node->left == nullptr && node->right == nullptr) {
                    auto mid((node->start + node->end) >> 1);
                    node->left = new SegmentTreeNode(node->start, mid, 0);
                    node->right = new SegmentTreeNode(mid + 1, node->end, 0);
                    s.push(node->left);
                    s.push(node->right);
                }
                else {
                    node->max = max(node->left->max, node->right->max);
                    s.pop();
                }
            }
        }
        return root;
    }
};
