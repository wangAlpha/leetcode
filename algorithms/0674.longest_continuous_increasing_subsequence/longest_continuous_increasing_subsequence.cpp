class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int result = 1;
        int curr_sequence = 1;
        int last = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (last >= nums[i]) {
                curr_sequence = 0;
            }
            curr_sequence += 1;
            result = max(result, curr_sequence);
            last = nums[i];
        }
        return result;
    }
};