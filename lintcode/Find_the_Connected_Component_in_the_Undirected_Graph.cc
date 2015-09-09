// DFS - recursive version
/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
        // Write your code here
        vector<vector<int> > ret;
        for (auto &&node : nodes) {
            if (visited_nodes.find(node->label) == visited_nodes.end()) {
                ret.resize(ret.size() + 1);
                iterateCC(node, ret.back());
                sort(ret.back().begin(), ret.back().end());
            }
        }
        return ret;
    }
    
private:
    void iterateCC(UndirectedGraphNode *node, vector<int> &cc) {
        visited_nodes.insert(node->label);
        cc.push_back(node->label);
        for (auto &&neighbor : node->neighbors)
            if (visited_nodes.find(neighbor->label) == visited_nodes.end())
                iterateCC(neighbor, cc);
    }

    unordered_set<int> visited_nodes;
};

// BFS - need additional queue but avoid recursion
/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
        // Write your code here
        vector<vector<int> > ret;
        for (auto &&node : nodes) {
            if (visited_nodes.find(node->label) == visited_nodes.end()) {
                ret.resize(ret.size() + 1);
                iterateCC(node, ret.back());
                sort(ret.back().begin(), ret.back().end());
            }
        }
        return ret;
    }
    
private:
    void iterateCC(UndirectedGraphNode *node, vector<int> &cc) {
        queue<UndirectedGraphNode *> q;
        q.push(node);
        while (!q.empty()) {
            auto node(q.front());
            q.pop();
            if (visited_nodes.find(node->label) == visited_nodes.end()) {
                visited_nodes.insert(node->label);
                cc.push_back(node->label);
                for (auto &&neighbor : node->neighbors)
                    if (visited_nodes.find(neighbor->label) == visited_nodes.end())
                        q.push(neighbor);
            }
        }
    }

    unordered_set<int> visited_nodes;
};
