// O(n^2) time complexity
class Solution {
public:
    string getPermutation(int n, int k) {
        string ret;
        vector<int> factorial(n, 1);
        for (int i(1); i < n; ++i)
            factorial[i] *= (factorial[i - 1] * i);
        vector<char> dict(n);
        iota(dict.begin(), dict.end(), '1');
        --k;
        for (int i(n - 1); i >= 0; --i) {
            int idx(k / factorial[i]);
            ret += dict[idx];
            k %= factorial[i];
            dict.erase(next(dict.begin(), idx));
        }
        return ret;
    }
};
