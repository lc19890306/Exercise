#include "TreeNode.hh"

#include <unordered_map>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

void printBinaryTree(TreeNode *root) {
  unordered_map<int, vector<int> > hash_map;
  queue<pair<TreeNode *, int> > q;
  q.push(make_pair(root, 0));
  int lower_bound(INT_MAX), upper_bound(INT_MIN);
  while (!q.empty()) {
    auto pair(q.front());
    q.pop();
    if (!pair.first)
      continue;
    lower_bound = min(lower_bound, pair.second);
    upper_bound = max(upper_bound, pair.second);
    hash_map[pair.second].push_back(pair.first->val);
    if (pair.first->left)
      q.push(make_pair(pair.first->left, pair.second - 1));
    if (pair.first->right)
      q.push(make_pair(pair.first->right, pair.second + 1));
  }
  for (int i(lower_bound); i <= upper_bound; ++i) {
    copy(hash_map[i].begin(), hash_map[i].end(), ostream_iterator<int>(cout, " "));
    cout << endl;
  }
}

TreeNode * constructTree(const vector<char> &vals) {
  vector<TreeNode *> nodes(vals.size());
  for (int i(0); i < vals.size(); ++i) {
    if ('#' == vals[i])
      continue;
    nodes[i] = new TreeNode(vals[i] - '0');
    if (!i)
      continue;
    auto parent((i - 1) >> 1);
    if (i & 1)
      nodes[parent]->left = nodes[i];
    else
      nodes[parent]->right = nodes[i];
  }
  return nodes.empty() ? nullptr : nodes[0];
}

int main() {
  vector<char> vals;
  // vector<char> vals{'1', '2', '3', '4', '5', '6', '7', '#', '#', '#', '#', '#', '8', '#', '9'};
  printBinaryTree(constructTree(vals));
  return 0;
}
