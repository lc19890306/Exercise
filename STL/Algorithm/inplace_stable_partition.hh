#pragma once

// distance
#include <algorithm>

namespace Algo {

template<typename Iter, typename Cmp>
Iter inplace_stable_partition(Iter b, Iter e, Cmp pred) {
    if (b == e) return e;
    if (distance(b, e) == 1) return pred(*b) ? ++b : b; // if predicate is satisfied, return next element
    auto m = b + distance(b, e) / 2;
    b = inplace_stable_partition(b, m, pred); // return the index partitioning the left sub-container
    e = inplace_stable_partition(m, e, pred); // return the index partitioning the right sub-container
    return (rotate)(b, m, e); // rotate (swap) the right partition of the left sub-container with the left partition of the right sub-container
    // return b + distance(m, e); // return the new index after rotation, beginning with the index partitioning the left sub-container while the distance is the length of the left partition of the right sub-container
}

}; // namespace Algo
