#include <iostream>

int gcd(const int &x, const int &y) {
  if (0 == x || 0 == y)
    return 0;
  // if (x == y)
  //   return x;
  // if (1 == x || 1 == y)
  //   return 1;
  auto smaller(std::min(x, y));
  auto larger(std::max(x, y));
  while (0 < smaller) {
    auto temp(smaller);
    smaller = larger % smaller;
    larger = temp;
  }
  return larger;
}

int lcm(const int &x, const int &y) {
  if (0 == x || 0 == y)
    return 0;
  return x * y / gcd(x, y);
}

int main(int argc, char **argv) {
  auto x(std::atoi(argv[1])), y(std::atoi(argv[2]));
  std::cout << "Greatest Common Divisor for " << x << " and " << y << " is " << gcd(x, y) << std::endl;
  std::cout << "Least Common Multiple for " << x << " and " << y << " is " << lcm(x, y) << std::endl;
  return EXIT_SUCCESS;
}
