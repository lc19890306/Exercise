// O(logn) time complexity (logn / log10 actually)
// http://blog.csdn.net/xudli/article/details/46798619
// 以算百位上1为例子:   假设百位上是0, 1, 和 >=2 三种情况: 
// case 1: n=3141092, a= 31410, b=92. 计算百位上1的个数应该为 3141 *100 次.
// case 2: n=3141192, a= 31411, b=92. 计算百位上1的个数应该为 3141 *100 + (92+1) 次. 
// case 3: n=3141592, a= 31415, b=92. 计算百位上1的个数应该为 (3141+1) *100 次. 
// 以上三种情况可以用 一个公式概括:
// (a + 8) / 10 * i + (a % 10 == 1) * (b + 1);
// a = n / i;
// b = n % i
class Solution {
public:
    int countDigitOne(int n) {
        int ret(0);
	// use long to avoid overflow (i * 10 may be greater than INT_MAX)
        for (long i(1); i <= n; i *= 10)
            ret += (n / i + 8) / 10 * i + (n / i % 10 == 1) * (n % i + 1);
        return ret;
    }
};
