class Solution {
    const int direction[5] = {-1, 0, 1, 0, -1};
public:
    int shortestBridge(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> points;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    markIsland(points, grid, i, j);
                    goto done;
                }
            }
        }
done:
        
        return searchIsland(points, grid);
    }
    int searchIsland(queue<pair<int,int>> &points, vector<vector<int>> &grid) {
        const int m = grid.size(), n = grid[0].size();
        int level = 0;
        while (!points.empty()) {
            ++level;
            int n_points = points.size();
            while (n_points--) {
                auto [r, c] = points.front();
                points.pop();
                for (int k = 0; k < 4; ++k) {
                    const int x = r + direction[k];
                    const int y = c + direction[k + 1];
                    if (x >= 0 && y >= 0 && x < m && y < n) {
                        if (grid[x][y] == 2) {
                            continue;
                        }
                        if (grid[x][y] == 1) {
                            return level;
                        }
                        points.emplace(make_pair(x, y));
                        grid[x][y] = 2;
                    }
                }
            }
        }
        return level;
    }
    void markIsland(queue<pair<int, int>> &points, vector<vector<int>> &grid, int i, int j) {
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == 2) {
            return;
        }
        if (grid[i][j] == 0) {
            points.emplace(make_pair(i, j));
            return;
        }
        grid[i][j] = 2;
        markIsland(points, grid, i + 1, j);
        markIsland(points, grid, i - 1, j);
        markIsland(points, grid, i, j + 1);
        markIsland(points, grid, i, j - 1);
    }
};