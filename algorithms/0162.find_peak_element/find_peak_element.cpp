class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        size_t lo = 0, hi = nums.size() - 1;
        for (size_t i = 0; i < hi; ++i) {
            if (nums[i] > nums[i + 1]) {
                return i;
            }
        }
        return hi;
    }
};