class Solution {
public:
    int lastStoneWeightII(const vector<int>& stones) {
        const int sum = accumulate(stones.begin(), stones.end(), 0);
        const int target = (sum >> 1);
        int dp[3000] = {0};
        for (const int&stone: stones) {
            for (int j = target; j >= stone; --j) {
                dp[j] = max(dp[j], dp[j - stone] + stone);
            }
        }
        return sum - (dp[target] << 1);
    }
};