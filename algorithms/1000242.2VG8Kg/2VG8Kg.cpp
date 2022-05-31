class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        size_t right = 0;
        int sum = 0;
        for (size_t left = 0; left < nums.size(); ++left) {
            while (right < nums.size() && sum < target) {
                sum += nums[right];
                right += 1;
            }
            if (sum < target) {
                break;
            }
            sum -= nums[left];
            ans = min(ans, static_cast<int>(right - left));
        }
        return ans == INT_MAX ? 0 : ans;
    }
};