#ifndef POINT_HH
#define POINT_HH

  struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
  };

#endif	// POINT_HH
