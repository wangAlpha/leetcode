class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        return max(robRange(nums, 0, nums.size() - 2), robRange(nums, 1, nums.size() - 1));
    }
    int robRange(const vector<int> &nums, int lo, int hi) {
        int first = nums[lo], second = max(nums[lo], nums[lo+1]);
        for (int i = lo + 2; i <= hi; ++i) {
            const int t = second;
            second = max(first + nums[i], second);
            first = t;
        }
        return second;
    }
};