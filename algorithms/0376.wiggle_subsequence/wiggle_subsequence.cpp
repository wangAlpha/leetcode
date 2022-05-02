class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        int count = 1, last = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            const int curr = nums[i + 1] - nums[i];
            if ((curr > 0 && last <= 0)||(last >= 0 && curr < 0)) {
                ++count;
                last = curr;
            }
        }
        return count;
    }
};