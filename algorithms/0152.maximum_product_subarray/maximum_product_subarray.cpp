class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0], maxF = nums[0], minF = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            const int mx = maxF, mn = minF;
            const int &n = nums[i];
            maxF = max({mx * n, mn * n, n});
            minF = min({mx * n, mn * n, n});
            ans = max(ans, maxF);
        }
        return ans;
    }
};