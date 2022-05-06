class Solution {
public:
    bool canPartition(const vector<int>& nums) {
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 0x1 == 0x1) {
            return false;
        }
        const int target = sum >> 1;
        vector<int> dp(target + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = target; j >= nums[i]; --j) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp.back() == target;
    }
};