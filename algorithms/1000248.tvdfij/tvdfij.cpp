class Solution {
public:
    int pivotIndex(const vector<int>& nums) {
        const int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (sum * 2 + nums[i] == total) {
                return i;
            }
            sum += nums[i];
        } 
        return -1;
    }
};