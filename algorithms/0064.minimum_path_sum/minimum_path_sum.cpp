class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const size_t m = grid.size(), n = grid[0].size();
        vector<vector<int>> path_sum(m, vector<int>(n, 0));
        path_sum[0][0] = grid[0][0];
        for (size_t i = 1; i < n; ++i) {
            path_sum[0][i] = path_sum[0][i - 1] + grid[0][i];
        }
        for (size_t i = 1; i < m; ++i) {
            path_sum[i][0] = path_sum[i - 1][0] + grid[i][0];
        }
        for (size_t i = 1; i < m;  ++i) {
            for (size_t j = 1; j < n; ++j) {
                path_sum[i][j] = min(path_sum[i - 1][j], path_sum[i][j - 1]) + grid[i][j];
            }
        } 
        return path_sum[m - 1][n - 1];
    }
};