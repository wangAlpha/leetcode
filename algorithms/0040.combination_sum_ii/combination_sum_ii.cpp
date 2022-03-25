class Solution {
public:
    void backtracking(const vector<int> &candidates, int index, int sum, int target) {
        if (sum == target) {
            result_.push_back(candidate_);
            return;
        }
        for (int i = index; i < candidates.size() && sum + candidates[i] <= target; ++i) {
            if (i > index && candidates[i-1] == candidates[i]) {
                continue;
            }
            sum += candidates[i];
            candidate_.push_back(candidates[i]);
            backtracking(candidates, i + 1, sum, target);
            sum -= candidates[i];
            candidate_.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.empty()) {
            return {};
        }
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, 0, 0, target);
        return result_;
    }
private:
    vector<vector<int>> result_;
    vector<int> candidate_;
};