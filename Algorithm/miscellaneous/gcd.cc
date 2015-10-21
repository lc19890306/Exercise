#include <iostream>

int gcd(int x, int y) {
  if (x * y == 0)
    return 0;
  while (x > 0) {
    auto temp(x);
    x = y % x;
    y = temp;
  }
  return y;
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
