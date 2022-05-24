class Solution {
public:
    int singleNonDuplicate(const vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            const int mi = lo + (hi - lo) / 2;
            if (nums[mi] == nums[mi ^ 1]) {
                lo = mi + 1;
            } else {
                hi = mi;
            }
        }
        return nums[hi];
    }
};