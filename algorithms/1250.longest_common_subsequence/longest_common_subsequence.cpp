class Solution {
public:
    int longestCommonSubsequence(const string &text1, const string &text2) {
        const int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m+1, vector(n+1, 0));
        for (int i = 1; i <= m; ++i) {
            const char &c1 = text1[i-1];
            for (int j = 1; j <= n; ++j) {
                const char &c2 = text2[j-1];
                if (c1 == c2) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[m][n];
    }
};