class Solution {
public:
    int minDistance(const string& word1, const string& word2) {
        const size_t m = word1.length(), n = word2.length();
        vector<int> dp(n + 1);
        vector<int> last(n + 1);
        for (size_t i = 1; i <= n; ++i) {
            dp[i] = i;
        }
        for (size_t i = 1; i <= m; ++i) {
            dp.swap(last);
            dp[0] = i;
            for (size_t j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = last[j - 1];
                } else {
                    dp[j] = min(last[j], dp[j - 1]) + 1;
                }
            }
        }
        return dp[n];
    }
};