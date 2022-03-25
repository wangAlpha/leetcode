class Solution {
public:
    void backtracking(const vector<int> &nums, int index) {
        if (sequence_.size() > 1) {
            subsequences_.push_back(sequence_);
        }
        unordered_set<int> uset;
        for (int i = index; i < nums.size(); ++i) {
            if ((!sequence_.empty() && sequence_.back() > nums[i])
                || uset.find(nums[i]) != uset.end()) {
                    continue;
            }
            uset.insert(nums[i]);
            sequence_.push_back(nums[i]);
            backtracking(nums, i + 1);
            sequence_.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return subsequences_;
    }
private:
    vector<vector<int>> subsequences_;
    vector<int> sequence_;   
};