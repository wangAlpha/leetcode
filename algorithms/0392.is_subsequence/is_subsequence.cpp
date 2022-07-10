class Solution {
public:
    bool isSubsequence(const string &sub, const string &str) {
        if (sub.size() > str.size()) {
            return false;
        }
        const size_t m = sub.size(), n = str.size();
        vector<int> dp(m + 1, 0);
        vector<int> last(m + 1, 0);
        for (size_t i = 1; i <= n; ++i) {
            dp.swap(last);
            for (size_t j = 1; j <= m; ++j) {
                if (str[i - 1] == sub[j - 1]) {
                    dp[j] = last[j - 1] + 1;
                } else {
                    dp[j] = max(last[j], dp[j - 1]);
                }
            }
        }
        return dp[m] == m;
    } 
};