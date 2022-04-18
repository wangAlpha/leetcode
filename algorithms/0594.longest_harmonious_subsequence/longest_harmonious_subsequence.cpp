class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        for (int i = 0, j = 0; j < nums.size(); ++j) {
            while (i < j && nums[j] - nums[i] > 1) ++i;
            if (nums[j] - nums[i] == 1) {
                result = max(result, j - i + 1);
            }
        }
        return result;
    }
};