#pragma once

#include <algorithm>

namespace Algo {

template<typename Iter, typename Cmp>
Iter inplace_stable_partition(Iter b, Iter e, Cmp pred) {
    if (b == e) return e;
    if (distance(b, e) == 1) return pred(*b) ? ++b : b;
    auto m = b + distance(b, e) / 2;
    b = inplace_stable_partition(b, m, pred);
    e = inplace_stable_partition(m, e, pred);
    rotate(b, m, e);
    return b + distance(m, e);
}

}; // namespace Algo
