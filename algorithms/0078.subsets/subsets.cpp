class Solution {
public:
    void backtracking(const vector<int>& nums, int index) {
        subsets_.push_back(path_);
        if (index > nums.size()) {
            return;
        }
        for (int i = index; i < nums.size(); ++i) {
            path_.push_back(nums[i]);
            backtracking(nums, i+1);
            path_.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return subsets_;
    }
private:
    vector<vector<int>> subsets_;
    vector<int> path_;
};