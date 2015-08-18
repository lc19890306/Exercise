#include <string>
#include <cctype>

using namespace std;

int myAtoi(string str) {
  if (str.empty())
    return 0;
  int ret(0);
  for (auto it(str.rbegin()); it != str.rend(); ++it) {
    if (*it == '-')
      ret = -ret;
    else {
      if (isdigit(*it)) {
	auto num(*it - '0');
	ret = ret * 10 + num;
      }
    }
  }
  return ret;
}

int main() {
  int ret = myAtoi("1");
  return 0;
}
