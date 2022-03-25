class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[] = {cost[0], cost[1]};
        int sum = 0;
        for (int i = 2; i < cost.size(); ++i) {
            sum = min(dp[0], dp[1]) + cost[i];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return min(dp[0], dp[1]);
    }
};