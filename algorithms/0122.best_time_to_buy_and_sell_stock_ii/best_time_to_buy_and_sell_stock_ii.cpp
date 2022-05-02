class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        int profit = 0;
        int last = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            const int diff = prices[i] - last;
            profit += max(diff, 0);
            last = prices[i];
        }
        return profit;
    }
};