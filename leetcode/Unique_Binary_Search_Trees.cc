// DFS solution - O(n) time and space complexity
// foreach root i in [1, n], num[i] = num[i - 1] * num[n - i]
// num[i - 1] computes the number of trees on the left [1, i - 1]
// num[n - i] computes the number of trees on the right [i + 1, n] (equals [1, n - i])
// use a static vector to collect all the results in the recursions
class Solution {
public:
    int numTrees(int n) {
        if (n < 2)
            return 1;
        static vector<int> num;
        if (n + 1 > num.size())
            num.resize(n + 1);
        if (num[n])
            return num[n];
        int ret(0);
        for (int i(1); i <= n; ++i)
            ret += (numTrees(i - 1) * numTrees(n - i));
        num[n] = ret;
        return ret;
    }
};
