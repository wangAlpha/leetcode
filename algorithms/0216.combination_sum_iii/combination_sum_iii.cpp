class Solution {
public:
    void backtracking(int k, int n, int index, int sum) {
        if (sum > n) {
            return;
        }
        if (path_.size() == k) {
            if (sum == n) {
                result_.emplace_back(path_);
            }
            return;
        }
        for (int i = index; i <= 9; ++i) {
            sum += i;
            path_.push_back(i);
            backtracking(k, n, i + 1, sum);
            sum -= i;
            path_.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1, 0);
        return result_;
    }
private:
    vector<int> path_;
    vector<vector<int>> result_;
};