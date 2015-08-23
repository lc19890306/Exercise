/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr)
            return node;
        auto it(nodes.find(node->label));
        if (it != nodes.end())
            return it->second;
        UndirectedGraphNode *ret = new UndirectedGraphNode(node->label);
        nodes.insert(make_pair(ret->label, ret));
        for (auto &&neighbor : node->neighbors)
            ret->neighbors.push_back(cloneGraph(neighbor));
        return ret;
    }

private:
    unordered_map<int, UndirectedGraphNode *> nodes;
};
