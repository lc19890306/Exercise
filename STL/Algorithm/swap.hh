#ifndef SWAP_HH
#define SWAP_HH

#include <algorithm>

using std::move;

namespace Algo {

template <class T>
void swap(T &a, T &b) {
  auto temp(std::move(a));
  a = std::move(b);
  b = std::move(temp);
}

};				// namespace Algo

#endif	// SWAP_HH
