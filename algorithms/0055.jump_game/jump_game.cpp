class Solution {
public:
    bool canJump(const vector<int>& nums) {
        const int len = nums.size();
        bool ans = false;
        int right_most = 0;
        for (int i = 0; i < len; ++i) {
            if (i <= right_most) {
                right_most = max(right_most, i + nums[i]);
            }
            if (right_most >= len - 1) {
                ans = true;
                break;
            }
        }
        return ans;
    }
};