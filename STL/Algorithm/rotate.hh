#pragma once

namespace Algo {

    template<typename Iter>
    Iter rotate(Iter b, Iter m, Iter e) {
        if (b == m) return e;
        if (m == e) return b;
        auto r = m, w = b, n = b;
        while (r != e) {
            if (w == n) {
                n = r;
            }
            Algo::iter_swap(w++, r++);
        }
        (rotate)(w, n, r); // 此处加括号阻止ADL，默认使用namespace内的函数，不加会触发ADL有可能会引起歧义无法编译
        return w; // w最后指向的就是rotate之后原来的b现在所指向的位置，即b + (e - m)
    }

}; // namespace Algo
