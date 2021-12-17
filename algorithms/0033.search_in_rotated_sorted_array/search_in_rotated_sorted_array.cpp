class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int lo = 0;
        int hi = nums.size() - 1;
        
        while (lo <= hi) {
            int mi = (lo + hi) / 2;
            if (target == nums[mi]) {
                return mi;
            };
            
            if (nums[mi] >= nums[lo]) {
                if (nums[lo] <= target && target <= nums[mi]) {
                    hi = mi - 1;
                } else {
                    lo = mi + 1;
                }
            } else {
                if (nums[mi] <= target && target <= nums[hi]) {
                    lo = mi + 1;
                } else {
                    hi = mi - 1;
                }
            }
        }
        return -1;
    }
};