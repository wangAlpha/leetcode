class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        const size_t n = nums1.size(), m = nums2.size();
        vector<int> dp(m + 1, 0);
        vector<int> last(m + 1, 0);
        for (size_t i = 1; i <= n; ++i) {
            for (size_t j = 1; j <= m; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[j] = last[j - 1] + 1;
                } else {
                    dp[j] = max(last[j], dp[j - 1]);
                }
            }
            dp.swap(last);
        }
        return max(dp[m], last[m]);
    }
};