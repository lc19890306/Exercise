#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
  Node() {}
  Node(int idx, int val) : idx(idx), val(val) {}
  bool operator()(const Node &a, const Node &b) {
    return a.val > b.val;
  }
  int idx;
  int val;
};

vector<int> merge_sort(vector<vector<int> > &vecs) {
  for (auto &&vec : vecs)
    sort(vec.begin(), vec.end(), greater<int>());
  priority_queue<Node, vector<Node>, Node> q;
  for (int i(0); i < vecs.size(); ++i) {
    if (!vecs[i].empty()) {
      q.push(Node(i, vecs[i].back()));
      vecs[i].pop_back();
    }
  }
  vector<int> ret;
  while (!q.empty()) {
    auto node(q.top());
    ret.push_back(node.val);
    q.pop();
    if (!vecs[node.idx].empty()) {
      q.push(Node(node.idx, vecs[node.idx].back()));
      vecs[node.idx].pop_back();
    }
  }
  return ret;
}

int main() {
  vector<vector<int> > vecs{
    {1, 2, 3, 4, 8},
      {3, 0, 3, 1, 9},
	{2, 4, 8, 0, 1},
	  {3, 4, 1, 5, 2}
  };

  auto ret(merge_sort(vecs));
  cout << is_sorted(ret.begin(), ret.end()) << endl;
  copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  return 0;
}
