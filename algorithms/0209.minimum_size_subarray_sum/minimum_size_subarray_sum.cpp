class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int sum = 0;
        size_t left = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while (left <= i && sum >= target) {
                ans = min(ans, static_cast<int>(i - left + 1));
                sum -= nums[left];
                ++left;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};