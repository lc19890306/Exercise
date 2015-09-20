#ifndef MEDIAN_HH
#defin MEDIAN_HH

namespace Algo {

template<class T>
T median(const T &a, const T &b, const T &c) {
  if (a <= b && b <= c) return b;
  if (a <= c && c <= b) return c;
  if (b <= a && a <= c) return a;
  if (b <= c && c <= a) return c;
  if (c <= a && a <= b) return a;
  if (c <= b && b <= a) return b;
}

};				// namespace Algo

#endif	// MEDIAN_HH
