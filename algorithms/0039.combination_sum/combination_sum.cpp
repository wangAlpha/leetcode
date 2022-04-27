class Solution {
public:
    void backtracking(const vector<int> &candidates, vector<int> &path, int sum, int index) {
        if (sum < 0) {
            return ;
        }
        if (sum == 0) {
            paths_.push_back(path);
            return;
        }
        for (int i = index; i < candidates.size() && sum - candidates[i] >= 0; ++i) {
            path.push_back(candidates[i]);
            sum -= candidates[i];
            backtracking(candidates, path, sum, i);
            sum += candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, path, target, 0);
        return paths_;
    }
private:
    vector<vector<int>> paths_;
};