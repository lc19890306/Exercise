#include <string>
#include <iostream>

using namespace std;

int ret(INT_MAX);

// Backtracking solution - O(k^n) where k is the length of s
void findMin_helper(string s, int n) {
  if (n == 0)
    ret = min(ret, stoi(s));
  for (int i(0); i < s.length(); ++i) {
    auto temp(s);
    findMin_helper(temp.erase(i, 1), n - 1);
  }
}

int findMin(string s, int n) {
  if (s.length() < n)
    return 0;
  findMin_helper(s, n);
  return ret;
}

int main() {
  string s = "32451";
  auto ret(findMin(s, 2));
  cout << ret << endl;
  return 0;
}
