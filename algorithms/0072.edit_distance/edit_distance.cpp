class Solution {
public:
    int minDistance(const string& word1, const string& word2) {
        const int m = word1.size(), n = word2.size();
        vector<int> dp(n + 1);
        vector<int> last(n + 1);
        for (int i = 0; i <= n; ++i) {
            dp[i] = i;
        }
        for (int i = 1; i <= m; ++i) {
            dp.swap(last);
            dp[0] = i;
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = last[j - 1];
                } else {
                    dp[j] = min({dp[j - 1], last[j], last[j - 1]}) + 1;
                }
            }
        }
        return dp.back();
    }
};