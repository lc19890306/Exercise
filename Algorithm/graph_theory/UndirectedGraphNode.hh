#ifndef UNDIRECTEDGRAPHNODE_HH
#define UNDIRECTEDGRAPHNODE_HH

#include <vector>

using std::vector;

struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int label) : label(label) {}
};

#endif	// UNDIRECTEDGRAPHNODE_HH
