#ifndef DIRECTEDGRAPHNODE_HH
#define DIRECTEDGRAPHNODE_HH

#include <vector>

using std::vector;

  struct DirectedGraphNode {
      int label;
      vector<DirectedGraphNode *> neighbors;
      DirectedGraphNode(int x) : label(x) {};
  };

#endif	// DIRECTEDGRAPHNODE_HH
