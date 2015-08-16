#include "functions.hh"

#include <iostream>
#include <vector>

using namespace std;

int main() {
  std::vector<int> vec = {5, 2, 1, 6, 3};
  std::cout << *Algo::min_element(vec.begin(), vec.end()) << std::endl;
}
