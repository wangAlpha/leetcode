class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int last = nums[0];
        int sum = nums[0];
        int result = sum;
        for (int i = 1; i < nums.size(); ++i) {
            if (0 == nums[i]) {
                sum = 0;
            } else {
                sum += 1;
            }
            last = nums[i];
            result = max(result, sum);
        }
        return result;
    }
};