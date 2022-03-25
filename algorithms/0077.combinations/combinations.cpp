class Solution {
public:
    void backtracking(vector<vector<int>> &result, int n, int k, int index, vector<int> &path) {
        if (k == path.size()) {
            result.emplace_back(path);
            return;
        }
        for (int i = index; i <= n; ++i) {
            path.push_back(i);
            backtracking(result, n, k, i+1, path);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int>> result;
        backtracking(result, n, k, 1, path);
        return result;
    }
};