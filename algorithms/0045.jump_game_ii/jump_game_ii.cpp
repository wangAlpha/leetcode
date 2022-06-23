class Solution {
public:
    int jump(const vector<int>& nums) {
        int count = 0;
        int start = 0, end = 1;
        while (end < nums.size()) {
            int max_pos = 0;
            for (int i = start; i < end; ++i) {
                max_pos = max(max_pos, nums[i] + i);
            }
            start = end;
            end = max_pos + 1;
            ++count;
        }
        return count;
    }
};