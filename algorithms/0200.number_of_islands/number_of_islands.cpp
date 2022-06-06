class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int counter = 0;
        const int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    fillIslands(grid, i, j);
                    counter += 1;
                }
            }
        }
        return counter;
    }
    void fillIslands(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
            return ;
        }
        grid[i][j] = '2';
        fillIslands(grid, i - 1, j);
        fillIslands(grid, i, j - 1);
        fillIslands(grid, i + 1, j);
        fillIslands(grid, i, j + 1);
    }
};