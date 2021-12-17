class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {return vector<int>{-1, -1};}
        int lo = 0;
        int hi = nums.size();
        while (lo < hi) {
            const int mi = (hi + lo)/2;
            if (nums[mi] < target) {
                lo = mi + 1;
            } else {
                hi = mi;
            }
        }
        lo = lo < nums.size() ? lo : nums.size() -1;
        for (int i = lo; i >= 0; --i) {
            if (nums[i] == target) {
                lo =i;
            } else {
                break;
            }
        }
        hi = lo;
        for (int i = lo; i < nums.size(); ++i) {
            if (nums[i] == target) {
                hi = i;
            } else {
                break;
            }
        }
        lo = nums[lo] == target ? lo : -1;
        hi = nums[hi] == target ? hi: -1;
        return vector<int>{lo, hi};
    }
};