#include "TreeNode.hh"

#include <iostream>
#include <stack>

using namespace std;

double avg(TreeNode *root, double ret, int &count) {
  if (nullptr == root)
    return ret;
  ++count;
  ret -= (ret - root->val) / count;
  ret = avg(root->left, ret, count);
  return avg(root->right, ret, count);
}

double avg(TreeNode *root) {
  int count(0);
  return avg(root, 0, count);
}

// double avg(TreeNode *root) {
//   double ret(0);
//   stack<TreeNode *> s;
//   s.push(root);
//   int count(0);
//   while (!s.empty()) {
//     auto node(s.top());
//     s.pop();
//     ++count;
//     ret -= (ret - node->val) / count;
//     if (node->left)
//       s.push(node->left);
//     if (node->right)
//       s.push(node->right);
//   }
//   return ret;
// }

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  cout << avg(root) << endl;
  return 0;
}
