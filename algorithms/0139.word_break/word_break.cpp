class Solution {
public:
    bool wordBreak(string &s, vector<string>& words) {
        unordered_set<string> words_set(words.begin(), words.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= static_cast<int>(s.size()); ++i) {
            for (int j = 0; j < i; ++j) {
                string&& substr = s.substr(j, i - j);
                if (words_set.find(substr) != words_set.end() && dp[j]) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};