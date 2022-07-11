class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        vector<int> curr(prices.size(), 0);
        vector<int> buy(prices.size(), 0);
        vector<int> sell(prices.size(), 0);
        buy[0] = -prices[0];
        for (size_t i = 1; i < prices.size(); ++i) {
            curr[i] = max(curr[i - 1], sell[i - 1]);
            buy[i] = max(buy[i - 1], curr[i - 1] - prices[i]);
            sell[i] = buy[i - 1] + prices[i];
        }
        return max(curr.back(), sell.back());
    }
};