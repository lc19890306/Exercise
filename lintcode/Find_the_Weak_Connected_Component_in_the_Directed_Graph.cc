/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param nodes a array of directed graph node
     * @return a connected set of a directed graph
     */
    vector<vector<int>> connectedSet2(vector<DirectedGraphNode*>& nodes) {
        // Write your code here
      // read all the nodes' labels into a hash_table
      // just scan nodes in one iteration by read the nodes and their neighbors' labels
        unordered_set<int> hash_table;
        for (auto &&node : nodes) {
            hash_table.insert(node->label);
            for (auto &&neighbor : node->neighbors)
                hash_table.insert(neighbor->label);
        }
	// union node and its neighbors
        UnionFind uf(hash_table);
        for (auto &&node : nodes)
            for (auto &&neighbor : node->neighbors)
	      // in this problem uf.find is redundant
                uf.make_union(node->label, neighbor->label);
                // uf.make_union(uf.find(node->label), uf.find(neighbor->label));
        return print(uf);
    }
    
private:
    struct UnionFind {
        UnionFind(const unordered_set<int> &hash_table) {
	  // initialize all nodes' parents as themselves
            for (auto &&element : hash_table)
                parent.insert({element, element});
        }

      // compressed_find compared with regular find
      // make all the nodes from x to the root parent share the same root parent by using recursion
      // an alternative iterative version is to find x's root parent first and then modify all the nodes' parents
      // which demands two iterations
        int getParent(const int &x) {
            if (x != parent[x])
                parent[x] = getParent(parent[x]);
            return parent[x];
        }
        
        int find(const int &x) {
            return getParent(x);
        }

      // union is a preserved key word so use make_union instead
        void make_union(const int &x, const int &y) {
            auto parent_x(find(x)), parent_y(find(y));
	    // if the two nodes' parents are different, make them share the same parent
            if (parent_x != parent_y)
                parent[parent_x] = parent_y;
        }
        
        unordered_map<int, int> parent;
    };
    
    vector<vector<int> > print(UnionFind &uf) {
        unordered_map<int, vector<int> > wccs;
        vector<vector<int> > ret;
        for (auto &&pair : uf.parent)
	  // uf.find is necessary in here since each node in the hash_map may not have its real root parent after union-find
	  // additional adjustment is essential
            wccs[uf.find(pair.second)].push_back(pair.first);
        for (auto &&pair: wccs) {
            sort(pair.second.begin(), pair.second.end());
            ret.push_back(pair.second);
        }
        return ret;
    }
};
