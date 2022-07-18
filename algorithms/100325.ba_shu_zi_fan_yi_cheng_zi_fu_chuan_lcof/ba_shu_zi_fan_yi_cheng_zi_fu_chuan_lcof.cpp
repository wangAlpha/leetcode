class Solution {
public:
    int translateNum(int num) {
        const string && str = to_string(num);
        vector<int> dp(str.size() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (size_t i = 2; i <= str.size(); ++i) {
            const int n = (str[i - 2] - '0') * 10 + (str[i - 1] - '0');
            if (n >= 10 && n <= 25) {
                dp[i] = dp[i - 2] + dp[i - 1];
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp.back();
    }
};