class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return false;
        }
        int lo = 0;
        int hi = nums.size() - 1;
        
        while (lo <= hi) {
            int mi = (lo + hi) / 2;
            if (nums[mi] == target) {
                return true;
            }
            
            if (nums[lo] < nums[mi]) {
                if (nums[lo] <= target && nums[mi] >= target) {
                    hi = mi - 1;
                } else {
                    lo = mi + 1;
                }
            } else if (nums[lo] > nums[mi]){
                if (nums[mi] <= target && nums[hi] >= target) {
                    lo = mi + 1;
                } else {
                    hi = mi -1;
                }
            } else {
                lo ++;
                continue;
            }
        }
        return false;
    }
};