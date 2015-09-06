#ifndef SEGMENTTREENODE_HH
#define SEGMENTTREENODE_HH

#include <cstdlib>

  class SegmentTreeNode {
  public:
      int start, end;
      SegmentTreeNode *left, *right;
      SegmentTreeNode(int start, int end) {
          this->start = start, this->end = end;
          this->left = this->right = NULL;
      }
  };

#endif	// SEGMENTTREENODE_HH
