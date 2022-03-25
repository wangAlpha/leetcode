class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) {
            return nums.size();
        }
        int index = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[index] && i >= index + 1) {
                nums[++index] = nums[i];
            }
        }
        return index + 1;
    }
};