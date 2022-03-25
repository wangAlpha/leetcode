class Solution {
public:
    void backtracking(const vector<int> &nums, int index) {
        result_.push_back(path_);
        if (index >= nums.size()) {
            return;
        }
        for (int i = index; i < nums.size(); ++i) {
            if (i == index || nums[i-1] != nums[i]) {
                path_.push_back(nums[i]);
                backtracking(nums, i + 1);
                path_.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return result_;
    }
private:
    vector<vector<int>> result_;
    vector<int> path_;
};