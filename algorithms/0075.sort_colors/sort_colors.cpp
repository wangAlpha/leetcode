class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        for (int i = 0; i < nums.size(); ++i) {
            while (i <= hi && nums[i] == 2) {
                swap(nums[i], nums[hi]);
                hi -= 1;
            }
            if (nums[i] == 0) {
                swap(nums[i], nums[lo]);
                lo += 1;
            }
        }
    }
};