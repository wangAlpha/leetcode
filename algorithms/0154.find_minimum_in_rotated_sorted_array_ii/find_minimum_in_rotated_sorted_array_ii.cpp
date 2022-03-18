class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            const int mi = lo + ((hi - lo) >> 1);
            if (nums[mi] < nums[hi]) {
                hi = mi;
            } else if (nums[mi] > nums[hi]) {
                lo = mi + 1;
            } else {
                --hi;
            }
        }
        return nums[lo];
    }
};