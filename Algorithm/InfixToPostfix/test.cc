#include "InfixToPostfix.hh"

int main() {
  string str;
  while (std::cin >> str)
    InfixToPostfix(str);
  return 0;
}
