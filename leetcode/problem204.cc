class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        bool *isPrime = new bool[n];
//        vector<bool> isPrime(n, false);
        int counter(n >> 1);
        for (int i(3); i * i < n; i += 2)
            if (!isPrime[i])
                for (int j(i * i), step(i << 1); j < n; j += step) {
                    if (!isPrime[j]) {
                        isPrime[j] = true;
                        --counter;
                    }
                }
        delete [] isPrime;
        return counter;
    }
};
