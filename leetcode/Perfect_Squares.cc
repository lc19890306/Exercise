// Mathematical solution - Best and fastest
// A non-negative integer is the summation of four non-negative integers
// A positive integer is the summation of three non-negative integers if and only if n != (4^k) * (8 * m + 7)
class Solution {
public:
    int numSquares(int n) {
        if (isPerfectSquare(n))
            return 1;
        while ((n & 3) == 0)	// n % 4 == 0
            n >>= 2;
	// (n & 7) the parentheses are necessary
        if ((n & 7) == 7)	// n % 8 == 7
            return 4;
	// if n is NOT the summation of 1 or 4 non-negative integers
        for (int i(1); i * i < n; ++i)
            if (isPerfectSquare(n - i * i))
                return 2;
        return 3;
    }
    
private:
    bool isPerfectSquare(int n) {
        int temp(sqrt(n));
        return temp * temp == n;
    }
};

// BFS solution - O(n) time complexity because at worst each number will be visited
class Solution {
public:
    int numSquares(int n) {
        if (n < 2)
            return n;
        vector<bool> visited(n + 1);
        queue<pair<int, int> > q;
        q.push(make_pair(n, 0));
        while (!q.empty()) {
            auto pair(q.front());
            q.pop();
            auto max(sqrt(pair.first));
            for (int i(max); i > 0; --i) {
                auto key(pair.first - i * i);
                if (0 == key)
                    return pair.second + 1;
                if (!visited[key]) {
                    q.push(make_pair(key, pair.second + 1));
                    visited[key] = true;
                }
            }
        }
    }
};

// Regular DP - O(n^1.5) time complexity (n * sqrt(n))
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i(0); i <= n; ++i)
            for (int j(0), num; (num = i + j * j) <= n; ++j)
	      // if dp[i] + 1 < dp[i + j * j], update dp[i + j * j]
	      // because the difference between i and (i + j * j) is (j * j), only one perfect square
	      // we can use dp[i] + 1 to update dp[i + j * j]
                dp[num] = min(dp[num], dp[i] + 1);
        return dp[n];
    }
};

// Static DP1 - faster in this problem
class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp;
        int prev_size(dp.size());
        if (prev_size >= n + 1)
            return dp[n];
        dp.resize(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i(0); i <= n; ++i)
	    for (int j(1), num; (num = i + j * j) <= n; ++j)
                if (num >= prev_size)
                    dp[num] = min(dp[num], dp[i] + 1);
        return dp[n];
    }
};

// Static DP2 - faster than DP1
class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp;
        int prev_size(dp.size());
        if (prev_size >= n + 1)
            return dp[n];
        dp.resize(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i(0); i <= n; ++i)
            for (int j(max((int)sqrt(prev_size - i), 0)), num; (num = i + j * j) <= n; ++j)
                dp[num] = min(dp[num], dp[i] + 1);
        return dp[n];
    }
};

// Static DP3 - faster than DP2
class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp{0};
        int prev_size(dp.size());
        dp.resize(max(prev_size, n + 1), INT_MAX);
        for (int i(1), i2; (i2 = i * i) <= n; ++i)
            for (int j(max(prev_size, i2)); j <= n; ++j)
                if (dp[j] > dp[j - i2] + 1)
                    dp[j] = dp[j - i2] + 1;
        return dp[n];
    }
};
