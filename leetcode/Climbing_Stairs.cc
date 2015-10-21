// DP => math solution
// DP[i]: the number of distinct ways for i
// DP[0] = 1 because no steps and you only have one way to choose
// DP[1] = 1 because only one step to choose
// for DP[2], you can choose one step, then you will face DP[1] problem
// you can also choose two steps, then you will face DP[0] problem
// therefore, DP[2] = DP[0] + DP[1]
// for DP[3], you can choose one step, then you will face DP[2] problem
// you can also choose two steps, then you will face DP[1] problem
// therefore, DP[3] = DP[1] + DP[2]
// mathematically, it is actually to calculate fibonacci number
class Solution {
public:
    int climbStairs(int n) {
        int a(1), b(1), ret(b);
        while (--n > 0) {
            ret = a + b;
            a = b;
            b = ret;
        }
        return ret;
    }
};
