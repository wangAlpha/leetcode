class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k >= nums.size()) {
            k %= nums.size();
        }
        const size_t len = nums.size() - k;
        reverse(nums.begin(), nums.begin() + len);
        reverse(nums.begin() + len, nums.end());
        reverse(nums.begin(), nums.end());
    }
};