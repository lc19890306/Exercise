#ifndef ITER_SWAP_HH
#define ITER_SWAP_HH

#include "swap.hh"

namespace Algo {

template <class ForwardIt>
void iter_swap(ForwardIt a, ForwardIt b) {
  Algo::swap(*a, *b);
}

};				// namespace Algo

#endif	// ITER_SWAP_HH
