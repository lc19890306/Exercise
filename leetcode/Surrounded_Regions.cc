#include <vector>
#include <string>
#include <iostream>

using namespace std;

// // Clumsy union-find version using unordered_map - very slow
// class Solution {
// public:
//     void solve(vector<vector<char>>& board) {
//         unordered_map<size_t, vector<size_t> > nodes;
//         unordered_set<size_t> illegalKeys;
//         for (size_t row(0); row != board.size(); ++row)
//             for (size_t col(0); col != board[row].size(); ++col)
//                 if (board[row][col] == 'O') {
//                     auto key(row * board[row].size() + col);
// 		    nodes[key] = {};
//                     if (0 < col && board[row][col - 1] == 'O')
//                         nodes[key].push_back(key - 1);
//                     if (col < board[row].size() - 1 && board[row][col + 1] == 'O')
//                         nodes[key].push_back(key + 1);
//                     if (0 < row && board[row - 1][col] == 'O')
//                         nodes[key].push_back(key - board[row].size());
//                     if (row < board.size() - 1 && board[row + 1][col] == 'O')
//                         nodes[key].push_back(key + board[row].size());
//                     if (0 == col || board[row].size() - 1 == col || 0 == row || board.size() - 1 == row)
//                         illegalKeys.insert(key);
//                 }
//         UnionFind uf(nodes);
//         for (auto &&node : nodes)
//             for (auto &&neighbor : node.second)
//                 uf.make_union(node.first, neighbor);
//         unordered_map<size_t, vector<size_t> > regions;
//         setRegions(uf, illegalKeys, regions);
//         for (auto &&region : regions)
//             for (auto &&node : region.second)
//                 board[node / board[0].size()][node % board[0].size()] = 'X';
//     }
    
// private:
//     struct UnionFind {
//         UnionFind(unordered_map<size_t, vector<size_t> > &nodes) {
// 	  for (auto &&node : nodes) {
// 	    parent.insert({node.first, node.first});
//                 for (auto &&neighbor : node.second)
//                     parent.insert({neighbor, neighbor});
// 	  }
//         }
        
//         size_t getParent(size_t x) {
//             if (x != parent[x])
//                 parent[x] = getParent(parent[x]);
//             return parent[x];
//         }
        
//         size_t find(size_t x) {
//             return getParent(x);
//         }
        
//         void make_union(size_t x, size_t y) {
//             auto parent_x(find(x)), parent_y(find(y));
//             if (parent_x != parent_y)
//                 parent[parent_x] = parent_y;
//         }
        
//         unordered_map<size_t, size_t> parent;
//     };
    
//     void setRegions(UnionFind &uf,
//                     unordered_set<size_t> &illegalKeys,
//                     unordered_map<size_t, vector<size_t> > &regions) {
//         unordered_set<size_t> illegalRegions;
//         for (auto &&node : illegalKeys)
//             illegalRegions.insert(uf.find(node));
//         for (auto &&pair : uf.parent)
//             if (illegalRegions.find(uf.find(pair.first)) == illegalRegions.end())
//                 regions[uf.find(pair.first)].push_back(pair.first);
//     }
// };

// // Optimized version - union all illegal connected components
// class Solution {
// public:
//     void solve(vector<vector<char>>& board) {
//         if (board.empty())
//             return;
//         UnionFind uf(board[0].size() * board.size());
//         for (size_t row(0); row != board.size(); ++row)
//             for (size_t col(0); col != board[row].size(); ++col)
//                 if (board[row][col] == 'O') {
//                     auto key(row * board[row].size() + col);
//                     if (0 == col || board[row].size() - 1 == col || 0 == row || board.size() - 1 == row)
//                         uf.make_union(-1, key);
//                     if (0 < col && board[row][col - 1] == 'O')
//                         uf.make_union(key, key - 1);
//                     if (col < board[row].size() - 1 && board[row][col + 1] == 'O')
//                         uf.make_union(key, key + 1);
//                     if (0 < row && board[row - 1][col] == 'O')
//                         uf.make_union(key, key - board[row].size());
//                     if (row < board.size() - 1 && board[row + 1][col] == 'O')
//                         uf.make_union(key, key + board[row].size());
//                 }
//         for (size_t row(0); row != board.size(); ++row)
//             for (size_t col(0); col != board[row].size(); ++col)
//                 if (board[row][col] == 'O' && !uf.same(row * board[row].size() + col, -1))
//                     board[row][col] = 'X';
//     }
    
// private:
//     struct UnionFind {
//         UnionFind(long size) {
//             parent.insert({-1, -1});
//             for (long i(0); i != size; ++i)
//                 parent.insert({i, i});
//         }
        
//         long getParent(long x) {
//             if (x != parent[x])
//                 parent[x] = getParent(parent[x]);
//             return parent[x];
//         }
        
//         long find(long x) {
//             return getParent(x);
//         }
        
//         bool same(long x, long y) {
//             return find(x) == find(y);
//         }
        
//         void make_union(long x, long y) {
//             auto parent_x(find(x)), parent_y(find(y));
//             if (parent_x == -1 || parent_y == -1)
//                 parent[parent_x] = parent[parent_y] = -1;
//             else if (parent_x != parent_y)
//                 parent[parent_x] = parent_y;
//         }
        
//         unordered_map<long, long> parent;
//     };
// };

// // Using dynamic array instead of unordered_map is much faster
// class Solution {
// public:
//     void solve(vector<vector<char>>& board) {
//         if (board.empty())
//             return;
// 	// use the last node as the dummy node to union all illegal regions
//         UnionFind uf(board[0].size() * board.size() + 1);
//         for (size_t row(0); row != board.size(); ++row)
//             for (size_t col(0); col != board[row].size(); ++col)
//                 if (board[row][col] == 'O') {
//                     auto key(row * board[row].size() + col);
//                     if (0 == col || board[row].size() - 1 == col || 0 == row || board.size() - 1 == row)
//                         uf.make_union(board[row].size() * board.size(), key);
// 		    // No need to union leftwards and upwards, which are redundant
//                     // if (0 < col && board[row][col - 1] == 'O')
//                     //     uf.make_union(key, key - 1);
//                     if (col < board[row].size() - 1 && board[row][col + 1] == 'O')
//                         uf.make_union(key, key + 1);
//                     // if (0 < row && board[row - 1][col] == 'O')
//                     //     uf.make_union(key, key - board[row].size());
//                     if (row < board.size() - 1 && board[row + 1][col] == 'O')
//                         uf.make_union(key, key + board[row].size());
//                 }
//         for (size_t row(0); row != board.size(); ++row)
//             for (size_t col(0); col != board[row].size(); ++col)
//                 if (board[row][col] == 'O' && !uf.same(row * board[row].size() + col, board[row].size() * board.size()))
//                     board[row][col] = 'X';
//     }
    
// private:
//     struct UnionFind {
//         UnionFind(long size) {
//             parent = new long[size];
//             rank = new long[size];
// 	    // Using for loop to initialize parent and rank would be faster
//             iota(parent, parent + size, 0);
//             memset(rank, 0, size);
//         }
        
//         ~UnionFind() {
//             delete [] parent;
// 	    delete [] rank;
//         }
        
//       // Using iteration instead of recursion
//         long find(long x) {
//             while (x != parent[x]) {
//                 parent[x] = parent[parent[x]];
//                 x = parent[x];
//             }
//             return parent[x];
//         }
        
//         bool same(long x, long y) {
//             return find(x) == find(y);
//         }
        
//         void make_union(long x, long y) {
//             auto parent_x(find(x)), parent_y(find(y));
//             if (parent_x == parent_y)
//                 return;
// 	    // if x's depth is smaller than y's, merge x to y
//             if (rank[parent_x] < rank[parent_y])
//                 parent[parent_x] = parent_y;
// 	    // if y's depth is smaller than x's, merge y to x
//             else if (rank[parent_y] < rank[parent_x])
//                 parent[parent_y] = parent_x;
//             else {
// 	      // if x and y have the same depth, merge x to y and increment y's depth
//                 parent[parent_x] = parent_y;
//                 ++rank[parent_y];
//             }
//         }
        
//         long *parent;
//         long *rank;
//     };
// };

// Recursive-DFS - Corrected and appropriate for this problem
// Before correction, it suffers from stack overflow issue if recursion runs way too deep
// Counterexample:
// XOOOOOOOOX
// XXXXXXXXOX
// XOOOOOOOOX
// XOXXXXXXXX
// XOOOOOOOOX
// XXXXXXXXOX
// XOOOOOOOOX
// XOXXXXXXXX
// XOOOOOOOOX
// XXXXXXXXOX
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;
        for (int row(0); row != board.size(); ++row) {
            if ('O' == board[row].front())
                modify(row, 0, board);
            if ('O' == board[row].back())
                modify(row, board[row].size() - 1, board);
        }
        for (int col(0); col != board.front().size(); ++col) {
            if ('O' == board.front()[col])
                modify(0, col, board);
            if ('O' == board.back()[col])
                modify(board.size() - 1, col, board);
        }
        for (int row(0); row != board.size(); ++row)
            for (int col(0); col != board[row].size(); ++col)
                if ('O' == board[row][col])
                    board[row][col] = 'X';
                else if ('I' == board[row][col])
                    board[row][col] = 'O';
    }
    
private:
  // // Problematic DFS due to stack overflow
  //   void modify(int row, int col, vector<vector<char> > &board) {
  //       board[row][col] = 'I';
  //       if (0 < col && 'O' == board[row][col - 1])
  //           modify(row, col - 1, board);
  //       if (0 < row && 'O' == board[row - 1][col])
  //           modify(row - 1, col, board);
  //       if (col < board[row].size() - 1 && 'O' == board[row][col + 1])
  //           modify(row, col + 1, board);
  //       if (row < board.size() - 1 && 'O' == board[row + 1][col])
  //           modify(row + 1, col, board);
  //   }

  // By reduce the range for each modification
  // Recursion stack overflow can be avoided
    void modify(int row, int col, vector<vector<char> > &board) {
        board[row][col] = 'I';
        if (1 < col && 'O' == board[row][col - 1])
            modify(row, col - 1, board);
        if (1 < row && 'O' == board[row - 1][col])
            modify(row - 1, col, board);
	// BE CAREFUL!!! cast size_t to int
        if (col < (int)board[row].size() - 2 && 'O' == board[row][col + 1])
            modify(row, col + 1, board);
        if (row < (int)board.size() - 2 && 'O' == board[row + 1][col])
            modify(row + 1, col, board);
    }
};

// Iterative DFS - no stack overflow
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;
        for (int row(0); row != board.size(); ++row) {
            if ('O' == board[row].front())
                modify(row, 0, board);
            if ('O' == board[row].back())
                modify(row, board[row].size() - 1, board);
        }
        for (int col(0); col != board.front().size(); ++col) {
            if ('O' == board.front()[col])
                modify(0, col, board);
            if ('O' == board.back()[col])
                modify(board.size() - 1, col, board);
        }
        for (int row(0); row != board.size(); ++row)
            for (int col(0); col != board[row].size(); ++col)
                if ('O' == board[row][col])
                    board[row][col] = 'X';
                else if ('I' == board[row][col])
                    board[row][col] = 'O';
    }
    
private:
    void modify(int row, int col, vector<vector<char> > &board) {
        stack<pair<int, int> > s;
        s.push({row, col});
        while (!s.empty()) {
            auto pair(s.top());
            auto row(pair.first), col(pair.second);
            board[row][col] = 'I';
            s.pop();
            if (0 < col && 'O' == board[row][col - 1])
                s.push({row, col - 1});
            if (0 < row && 'O' == board[row - 1][col])
                s.push({row - 1, col});
            if (col < (int)board[row].size() - 1 && 'O' == board[row][col + 1])
                s.push({row, col + 1});
            if (row < (int)board.size() - 1 && 'O' == board[row + 1][col])
                s.push({row + 1, col});
        }
    }
};

// // BFS
// class Solution {
// public:
//     void solve(vector<vector<char>>& board) {
//         if (board.empty())
//             return;
//         for (int row(0); row != board.size(); ++row) {
//             if ('O' == board[row].front())
//                 modify(row, 0, board);
//             if ('O' == board[row].back())
//                 modify(row, board[row].size() - 1, board);
//         }
//         for (int col(0); col != board.front().size(); ++col) {
//             if ('O' == board.front()[col])
//                 modify(0, col, board);
//             if ('O' == board.back()[col])
//                 modify(board.size() - 1, col, board);
//         }
//         for (int row(0); row != board.size(); ++row)
//             for (int col(0); col != board[row].size(); ++col)
//                 if ('O' == board[row][col])
//                     board[row][col] = 'X';
//                 else if ('I' == board[row][col])
//                     board[row][col] = 'O';
//     }
    
// private:
//     void modify(int row, int col, vector<vector<char> > &board) {
//         board[row][col] = 'I';
//         queue<pair<int, int> > q;
//         q.push({row, col});
//         while (!q.empty()) {
//             auto pair(q.front());
//             q.pop();
//             if (0 < pair.second && 'O' == board[pair.first][pair.second - 1]) {
// 	      // MUST modify value first
// 	      // lazy modification is problematic because duplicated enqueuing may appear
// 	      // Counterexample:
// 	      // XOO
// 	      // XOO
// 	      // XXX
//                 board[pair.first][pair.second - 1] = 'I';
//                 q.push({pair.first, pair.second - 1});
//             }
//             if (0 < pair.first && 'O' == board[pair.first - 1][pair.second]) {
//                 board[pair.first - 1][pair.second] = 'I';
//                 q.push({pair.first - 1, pair.second});
//             }
//             if (pair.second + 1 < board[pair.first].size() && 'O' == board[pair.first][pair.second + 1]) {
//                 board[pair.first][pair.second + 1] = 'I';
//                 q.push({pair.first, pair.second + 1});
//             }
//             if (pair.first + 1 < board.size() && 'O' == board[pair.first + 1][pair.second]) {
//                 board[pair.first + 1][pair.second] = 'I';
//                 q.push({pair.first + 1, pair.second});
//             }
//         }
//     }
// };

int main() {
  vector<string> input{"O"};
  vector<vector<char> > board;
  for (auto &&str : input) {
    vector<char> vec;
    for (auto &&c : str)
      vec.push_back(c);
    board.push_back(vec);
  }
  Solution s;
  s.solve(board);
  for (auto &&vec : board) {
    for (auto &&c : vec)
	cout << c << " ";
    cout << endl;
  }
  return 0;
}
