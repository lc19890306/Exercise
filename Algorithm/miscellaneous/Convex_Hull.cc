#include <vector>
#include <iostream>
#include <fstream>

struct Point {
  Point(double x, double y) : x(x), y(y) {}
  void display(std::ostream &os) const {
    os << x << " " << y;
  }
  // not essential
  // friend std::ostream & operator<<(std::ostream &, const Point &);
  double x;
  double y;
};

std::ostream &
operator<<(std::ostream &os, const Point &point) {
  point.display(os);
  return os;
}

struct isSmaller {
  bool operator()(const Point &lhs, const Point &rhs) const {
    return lhs.x < rhs.x ? : lhs.x == rhs.x ? lhs.y < rhs.y : false;
  }
};

struct isSmaller2 {
  isSmaller2(const Point &point) : anchor(point) {}

  double coeficient(const Point &other) const {
    return (other.y - anchor.y) / (other.x - anchor.x);
  }

  double distance(const Point &point) const {
    auto distance_x(point.x - anchor.x), distance_y(point.y - anchor.y);
    return distance_x * distance_x + distance_y * distance_y;
  }
  bool operator()(const Point &lhs, const Point &rhs) const {
    // Final result only contains all polar points
    // First compare coeficient, if the same, compare distance to the anchor
    auto coeficient_lhs(coeficient(lhs)), coeficient_rhs(coeficient(rhs));
    return coeficient_lhs < coeficient_rhs ? : coeficient_lhs == coeficient_rhs ? distance(lhs) < distance(rhs) : false;
  }
  Point anchor;
};

// aka outer product
// <(p2.x - p1.x), (p2.y - p1.y)> X <(p4.x - p3.x), (p4.y - p3.y)>
double cross_product(const Point &p1, const Point &p2, const Point &p3, const Point &p4) {
  return (p2.y - p1.y) * (p4.x - p3.x) - (p2.x - p1.x) * (p4.y - p3.y);
}

std::vector<Point>
convexHull(std::vector<Point> &points) {
  if (points.size() < 3)
    return points;
  auto anchor(min_element(points.begin(), points.end(), isSmaller()));
  std::swap(*anchor, points.front());
  std::sort(points.begin() + 1, points.end(), isSmaller2(points.front()));
  std::vector<Point> ret;
  ret.push_back(points[0]);
  ret.push_back(points[1]);
  for (size_t i(2); i != points.size(); ++i) {
    if (cross_product(ret.back(), *(ret.rbegin() + 1), ret.back(), points[i]) <= 0)
      ret.pop_back();
    ret.push_back(points[i]);
  }
  return ret;
}

int main(int argc, char **argv) {
  std::fstream infile(argv[1]);
  std::vector<Point> points;
  double x, y;
  while (infile >> x >> y)
    points.push_back(Point(x, y));
  auto ret(convexHull(points));
  std::copy(ret.begin(), ret.end(), std::ostream_iterator<Point>(std::cout, "\n"));
}
