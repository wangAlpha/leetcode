class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (const auto& str: strs) {
            int zero_num = 0, one_num = 0;
            for (const char& c: str) {
                if (c == '1') {
                    ++one_num;
                } else {
                    ++zero_num;
                }
            }
            for (int i = m; i >= zero_num; --i) {
                for (int j = n; j >= one_num; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - zero_num][j - one_num] + 1);
                }
            }
        }
        return dp[m][n];
    }
};