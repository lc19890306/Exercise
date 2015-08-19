class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        int counter(0);
        for (int i(2); i < n; ++i)
            if (isPrime[i]) {
                ++counter;
                for (int j(i << 1); j < n; j += i)
                    isPrime[j] = false;
            }
        return counter;
    }
};
