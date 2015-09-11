// Union-Find version
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid.front().empty())
            return 0;
        int row_size(grid.size()), col_size(grid.front().size()), dummy_node(row_size * col_size);
        UnionFind uf(dummy_node + 1);
        for (int row(0); row != row_size; ++row)
            for (int col(0); col != col_size; ++col) {
                auto key(row * col_size + col);
                if ('1' != grid[row][col]) {
                    uf.make_union(key, dummy_node);
                    continue;
                }
// No need to union leftwards and upwards, which are redundant
                if (col + 1 < col_size && '1' == grid[row][col + 1])
                    uf.make_union(key, key + 1);
                if (row + 1 < row_size && '1' == grid[row + 1][col])
                    uf.make_union(key, key + col_size);
            }
        return uf.getCount() - 1;
    }
    
private:
    struct UnionFind {
        UnionFind(int size)
            : size(size),
              count(size),
              parent(new int[size]), 
              rank(new int[size]) {
            iota(parent, parent + size, 0);
            memset(rank, 0, size);
        }
        
        ~UnionFind() {
            delete[] parent;
            delete[] rank;
        }
        
        void setParent(int x, int y) {
            parent[x] = y;
        }
        
        int find(int x) {
            while (x != parent[x])
                x = parent[x] = parent[parent[x]];
            return parent[x];
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
                parent[parent_y] = parent_x;
                ++rank[parent_x];
            }
            --count;
        }
        
        int getCount() const {
            return count;
        }
        
        int size;
        int count;
        int *parent;
        int *rank;
    };
};

// // DFS version - maybe problematic due to stack overflow
// // recursive version is inappropriate
// // Using iterative DFS instead
// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int count(0);
//         for (int row(0); row != grid.size(); ++row)
//             for (int col(0); col != grid[row].size(); ++col)
//                 if ('1' == grid[row][col]) {
//                     ++count;
//                     eliminate(grid, row, col);
//                 }
//         return count;
//     }
    
// private:
//     void eliminate(vector<vector<char> > &grid, int row, int col) {
//         if (row < 0 || col < 0 || grid.size() <= row || grid.front().size() <= col)
//             return;
//         if ('0' == grid[row][col])
//             return;
//         grid[row][col] = '0';
//         eliminate(grid, row, col - 1);
//         eliminate(grid, row - 1, col);
//         eliminate(grid, row, col + 1);
//         eliminate(grid, row + 1, col);
//     }
// };

// BFS version
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count(0);
        for (int row(0); row != grid.size(); ++row)
            for (int col(0); col != grid[row].size(); ++col)
                if ('1' == grid[row][col]) {
                    ++count;
                    eliminate(grid, row, col);
                }
        return count;
    }
    
private:
    void eliminate(vector<vector<char> > &grid, int row, int col) {
        queue<pair<int, int> > q;
        q.push({row, col});
        while (!q.empty()) {
            auto pair(q.front());
            q.pop();
            if (pair.first < 0 || pair.second < 0 || grid.size() <= pair.first || grid.front().size() <= pair.second)
                continue;
            if ('0' == grid[pair.first][pair.second])
                continue;
            grid[pair.first][pair.second] = '0';
            q.push({pair.first, pair.second - 1});
            q.push({pair.first - 1, pair.second});
            q.push({pair.first, pair.second + 1});
            q.push({pair.first + 1, pair.second});
        }
    }
};
