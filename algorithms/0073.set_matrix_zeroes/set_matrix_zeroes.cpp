class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        vector<pair<int, int>> coords;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    coords.push_back({i, j});
                }
            }
        }
        for (auto &[x, y]: coords) {
            setZeroes(matrix, x, y);
        }
    }
    void setZeroes(vector<vector<int>>& matrix, int x, int y) {
        const int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            matrix[i][y] = 0;
        }
        for (int j = 0; j < n; ++j) {
            matrix[x][j] = 0;
        }
    }
};