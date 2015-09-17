#include <vector>
#include <ctime>
#include <random>
#include <algorithm>
#include <iostream>
// #include <iterator>

namespace Algo {

template<typename RandomIt>
void
shuffle(RandomIt first, RandomIt last) {
  auto count(std::distance(first, last));
  for (int i(count - 1); i > 0; --i)
    std::swap(first[i], first[rand() % (i + 1)]);
}

};				// namespace Algo

int main() {
  srand((unsigned)time(NULL));
  std::vector<int> deck(54);
  std::iota(deck.begin(), deck.end(), 0);
  std::copy(deck.begin(), deck.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
  Algo::shuffle(deck.begin(), deck.end());
  std::copy(deck.begin(), deck.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
}
