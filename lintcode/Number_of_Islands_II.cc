/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /**
     * @param n an integer
     * @param m an integer
     * @param operators an array of point
     * @return an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point>& operators) {
        // Write your code here
        auto dummy_node(n * m);
        if (operators.empty() || dummy_node < operators.size())
            return {};
        vector<int> ret;
        UnionFind uf(dummy_node + 1);
        for (auto &&point : operators) {
            auto key(point.x * m + point.y);
            uf.setParent(key);
            if (0 < point.y && !uf.same(key - 1, dummy_node))
                uf.make_union(key, key - 1);
            if (0 < point.x && !uf.same(key - m, dummy_node))
                uf.make_union(key, key - m);
            if (point.y + 1 < m && !uf.same(key + 1, dummy_node))
                uf.make_union(key, key + 1);
            if (point.x + 1 < n && !uf.same(key + m, dummy_node))
                uf.make_union(key, key + m);
            ret.push_back(uf.getCount() - 1);
        }
        return ret;
    }
    
private:
    struct UnionFind {
        UnionFind(int size) :
        size(size),
        count(1),
        parent(new int[size]),
        rank(new int[size]) {
// memset in here is wrong!!! because memset is used to set value based on bytes
// sizeof int equals 4, so each integer will be set as a combination [valuevaluevaluevalue]
// therefore, memset is mostly used for reset to 0
            // memset(parent, size, size - 1);
            fill_n(parent, size, size - 1);
            memset(rank, 0, size);
        }
        
        ~UnionFind() {
            delete[] parent;
            delete[] rank;
        }
        
        void setParent(int x) {
            parent[x] = x;
            ++count;
        }
        
        int find(int x) {
            while (x != parent[x])
                x = parent[x] = parent[parent[x]];
            return parent[x];
        }
        
        bool same(int x, int y) {
            return find(x) == find(y);
        }
        
        int getCount() const {
            return count;
        }
        
        void make_union(int x, int y) {
            auto parent_x(find(x)), parent_y(find(y));
            if (parent_x == parent_y)
                return;
            if (rank[parent_x] < rank[parent_y])
                parent[parent_x] = parent_y;
            else if (rank[parent_y] < rank[parent_x])
                parent[parent_y] = parent_x;
            else {
                parent[parent_x] = parent_y;
                ++rank[parent_y];
            }
            --count;
        }
        
        int size;
        int count;
        int *parent;
        int *rank;
    };
};
