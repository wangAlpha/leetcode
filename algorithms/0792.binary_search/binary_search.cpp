class Solution {
public:
   int search(const vector<int>& nums, int target) {
       int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            const int mi = lo + (hi - lo) / 2;
            if (nums[mi] == target) {
                return mi;
            } else if (nums[mi] < target) {
                lo = mi + 1;
            } else {
                hi = mi - 1;
            }
        }
        return -1;
    }
};