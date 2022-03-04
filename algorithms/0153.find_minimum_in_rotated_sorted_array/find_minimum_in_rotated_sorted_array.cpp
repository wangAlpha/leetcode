class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            const int mi = (lo + hi) >> 1;
            if (nums[mi] < nums[hi]) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return nums[lo];
    }
};