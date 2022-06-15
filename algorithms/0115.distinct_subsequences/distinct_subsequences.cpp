class Solution {
public:
    int numDistinct(const string& str, const string& substr) {
        if (str.size() < substr.size()) {
            return 0;
        }
        vector<uint64_t> dp(substr.size() + 1);
        vector<uint64_t> last(substr.size() + 1);
        dp[0] = 1;
        last[0] = 1;
        for (size_t i = 1; i <= str.size(); ++i) {
            dp.swap(last);
            for (size_t j = 1; j <= substr.size(); ++j) {
                if (str[i - 1] == substr[j - 1]) {
                    dp[j] = last[j - 1] + last[j];
                } else {
                    dp[j] = last[j];
                }
            }
        }
        return dp[substr.size()];
    }
};