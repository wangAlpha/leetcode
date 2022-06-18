class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        const int len = prices.size();
        vector<int> buy(len);
        vector<int> sell(len);
        buy[0] = -prices[0];
        for (size_t i = 1; i < len; ++i) {
            const auto last = i - 1;
            buy[i] = max(buy[last], sell[last] - prices[i]);
            sell[i] = max(sell[last], buy[last] + prices[i] - fee);
        }
        return sell.back();
    }
};