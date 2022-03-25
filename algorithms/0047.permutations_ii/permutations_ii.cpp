class Solution {
public:
    void backtracking(const vector<int> &nums, vector<bool> &used) {
        if (path_.size() == nums.size()) {
            permute_.push_back(path_);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i-1] == nums[i] && used[i-1] == false) {
                continue;
            }
            if (used[i] == false) {
                used[i] = true;
                path_.push_back(nums[i]);
                backtracking(nums, used);
                used[i] = false;
                path_.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return permute_;
    }
private:
    vector<vector<int>> permute_;
    vector<int> path_;
};