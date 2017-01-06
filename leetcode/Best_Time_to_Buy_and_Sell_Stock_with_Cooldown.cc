// DP solution - O(n) time and space complexity
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n(prices.size());
        if (n < 2)
            return 0;
        vector<int> s0(n), s1(n), s2(n);
        s1[0] = -prices[0];
        s2[0] = INT_MIN;
        for (int i(1); i < n; ++i) {
            s0[i] = max(s0[i - 1], s2[i - 1]);
            s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);
            s2[i] = s1[i - 1] + prices[i];
        }
        return max(s0.back(), s2.back());
    }
};

// Revised DP solution - O(n) time and O(1) space complexity
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n(prices.size());
        if (n < 2)
            return 0;
        int rest(0), hold(-prices[0]), sold(INT_MIN);
        for (int i(1); i < n; ++i) {
            auto pre_rest(rest); // store the previous state of rest in pre_rest
            rest = max(rest, sold);
            sold = hold + prices[i];
            hold = max(hold, pre_rest - prices[i]);
        }
        return max(sold, rest);
    }
};
