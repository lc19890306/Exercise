// DP solution - O(n) time complexity
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit(0), cur_profit(0);
        for (int i(1); i < prices.size(); ++i) {
            cur_profit = cur_profit < 0 ? prices[i] - prices[i - 1] : cur_profit + prices[i] - prices[i - 1];
            max_profit = max(max_profit, cur_profit);
        }
        return max_profit;
    }
};

// DP solution - O(n) time complexity
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit(0), curr_max_profit(0);
        for (int i(1); i < prices.size(); ++i) {
            curr_max_profit += prices[i] - prices[i - 1];
            curr_max_profit = max(curr_max_profit, 0);
            max_profit = max(max_profit, curr_max_profit);
        }
        return max_profit;
    }
};

// DP solution - O(n) time complexity
// Maintain min_price and max_profit
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit(0), min_price(INT_MAX);
        for (auto &&price : prices) {
            min_price = min(min_price, price);
            max_profit = max(max_profit, price - min_price);
        }
        return max_profit;
    }
};
