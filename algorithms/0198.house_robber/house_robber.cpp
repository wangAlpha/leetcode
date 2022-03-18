class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            const int t = second; 
            second = max(first + nums[i], second);
            first = t;
        }
        return second;
    }
};