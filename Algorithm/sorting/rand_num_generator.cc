#include "rand_num_generator.hh"

void
rand_num_generator::generate(const int &n, const int &modulo) {
  std::unordered_set<int> set;
  while (set.size() != n)
    set.insert(rand() % modulo);
  std::copy(set.begin(), set.end(), std::ostream_iterator<int>(outfile, " "));
}
