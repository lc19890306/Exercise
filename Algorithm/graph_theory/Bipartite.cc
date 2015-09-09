#include "UndirectedGraphNode.hh"

#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

typedef enum {RED, BLUE} Color;

// BFS
bool isBipartite(UndirectedGraphNode * node) {
  queue<UndirectedGraphNode *> q;
  unordered_map<UndirectedGraphNode *, Color> hash_map;
  q.push(node);
  hash_map[node] = RED;
  while (!q.empty()) {
    auto node(q.front());
    q.pop();
    auto color(hash_map[node]);
    for (auto &&neighbor : node->neighbors)
      if (hash_map.find(neighbor) == hash_map.end()) {
	hash_map[neighbor] = Color(color ^ BLUE);
	q.push(neighbor);
      }
      else if (hash_map[neighbor] == color)
	return false;
  }
  return true;
}

int main() {
  vector<UndirectedGraphNode *> nodes(6);
  for (size_t i(0); i != nodes.size(); ++i)
    nodes[i] = new UndirectedGraphNode(i);
  nodes[0]->neighbors.push_back(nodes[3]);
  nodes[0]->neighbors.push_back(nodes[5]);
  nodes[1]->neighbors.push_back(nodes[2]);
  nodes[1]->neighbors.push_back(nodes[4]);
  nodes[2]->neighbors.push_back(nodes[1]);
  nodes[2]->neighbors.push_back(nodes[3]);
  nodes[3]->neighbors.push_back(nodes[0]);
  nodes[3]->neighbors.push_back(nodes[2]);
  nodes[3]->neighbors.push_back(nodes[4]);
  nodes[4]->neighbors.push_back(nodes[1]);
  nodes[4]->neighbors.push_back(nodes[3]);
  nodes[4]->neighbors.push_back(nodes[5]);
  nodes[5]->neighbors.push_back(nodes[0]);
  nodes[5]->neighbors.push_back(nodes[4]);

  nodes[2]->neighbors.push_back(nodes[4]);
  nodes[4]->neighbors.push_back(nodes[2]);
  cout << boolalpha << isBipartite(nodes[3]) << endl;
}
