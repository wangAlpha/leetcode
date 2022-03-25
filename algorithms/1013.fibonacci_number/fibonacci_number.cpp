class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        int sum = 0;
        int dp[] = {0, 1};
        for (int i = 1; i < n; ++i) {
            sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return sum;
    }
};