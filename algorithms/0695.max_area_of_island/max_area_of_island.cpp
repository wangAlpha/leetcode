class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    int direction[] = {-1, 0, 1, 0, -1};
    const int m = grid.size();
    const int n = m ? grid[0].size() : 0;
    int area = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
        if (grid[i][j]) {
            int local_area = 1;
            grid[i][j] = 0;
            stack<pair<int, int>> island;
            island.push({i, j});
            while (!island.empty()) {
            auto [r, c] = island.top();
            island.pop();
            for (int k = 0; k < 4; ++k) {
                const int x = r + direction[k];
                const int y = c + direction[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y]) {
                grid[x][y] = 0;
                ++local_area;
                island.push({x, y});
                }
            }
            }
            area = max(area, local_area);
        }
        }
    }
    return area;
    }
};