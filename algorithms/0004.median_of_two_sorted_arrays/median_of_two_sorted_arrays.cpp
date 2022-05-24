class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const auto nums = merge_array(nums1, nums2);        
        const size_t len = nums.size();
        if (nums.size() & 0x01 == 0x01) {
            return nums[len / 2];
        } else {
            return (nums[len / 2] + nums[(len - 1)/2])/2.0;
        }
    }
    vector<int> merge_array(vector<int> &nums1, vector<int> &nums2) {
        vector<int> ans(nums1.size() + nums2.size());
        int i = 0, j = 0;
        int k = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                ans[k++] = nums1[i++];
            } else {
                ans[k++] = nums2[j++];
            }
        }
        while (i < nums1.size()) {
            ans[k++] = nums1[i++];
        }
        while (j < nums2.size()) {
            ans[k++] = nums2[j++];
        }
        return move(ans);
    }
};