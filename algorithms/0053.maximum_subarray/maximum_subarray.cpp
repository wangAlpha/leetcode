class Solution {
public:
    int maxSubArray(const vector<int>& nums) {
        int maximum = nums[0];
        int sum = 0;
        for (const auto &n: nums) {
           sum += n;
           maximum = max(sum, maximum);
           if (sum < 0) {
               sum = 0;
           }
        }
        return maximum;
    }
};