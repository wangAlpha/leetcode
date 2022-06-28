class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        size_t i = 0;
        while (i < nums.size()) {
            size_t j = i;
            while (j + 1 < nums.size() && nums[j] + 1 == nums[j + 1]) {
                ++j;
            }
            if (i != j) {
                ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
                i = j;
            } else {
                ans.push_back(to_string(nums[j]));
            }
            i = j + 1;
        }
        return ans;
    }
};