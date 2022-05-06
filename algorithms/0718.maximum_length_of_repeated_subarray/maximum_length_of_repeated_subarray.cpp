class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        vector<int> dp(nums2.size() + 1, 0);
        for (size_t i = 1; i <= nums1.size(); ++i) {
            for (size_t j = nums2.size(); j > 0; --j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[j] = dp[j - 1] + 1;
                } else {
                    dp[j] = 0;
                }
                result = max(dp[j], result);
            }
        }
        return result;
    }
};