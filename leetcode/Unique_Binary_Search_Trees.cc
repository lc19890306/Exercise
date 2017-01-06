// Memorization DP solution (DFS) - O(n^2) time and space complexity
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

// Regular DP solution - O(n^2) time and O(n) space complexity
// G[n]: the number of unique BST for a sequence of length n
// F[i, n], 1 <= i <= n: the number of unique BST, where the number i is the root of BST, and the sequence ranges from 1 to n
// G[n] = F[1, n] + F[2, n] + ... + F[n, n]
// G[0] = G[1] = 1
// F[i, n] = G[i - 1] * G[n - i], 1 <= i <= n
// G[n] = G[0] * G[n - 1] + G[1] * G[n - 2] + ... + G[n - 1] * G[0]
class Solution {
public:
    int numTrees(int n) {
        if (n < 2)
            return 1;
        vector<int> num(n + 1);
        num[0] = num[1] = 1;
        for (int i(2); i <= n; ++i)
            for (int j(0); j <= i; ++j)
                num[i] += num[j - 1] * num[i - j];
        return num[n];
    }
};

// Static DP solution
class Solution {
public:
    int numTrees(int n) {
        if (n < 2)
            return 1;
        static vector<int> num;
        int prev_size(num.size());
        if (n + 1 > prev_size)
            num.resize(n + 1);
        else
            return num[n];
        num[0] = num[1] = 1;
        for (int i(max(prev_size, 2)); i <= n; ++i)
            for (int j(0); j <= i; ++j)
                num[i] += num[j - 1] * num[i - j];
        return num[n];
    }
};
