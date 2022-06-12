class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 0x1 == 0x1) {
            return false;
        }
        const int target = sum / 2;
        vector<int> dp(target + 1);
        for (const int &n: nums) {
            for (int j = target; j >= n; --j) {
                dp[j] = max(dp[j], dp[j - n] + n);
            }
        }
        return dp[target] == target;
    }
};