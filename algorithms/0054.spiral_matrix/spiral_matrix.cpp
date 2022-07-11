class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> visted(m, vector<bool>(n, false));
        const int directions[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> elements; 
        int cnt = 0;
        int i = 0, j = 0, index = 0;
        while (cnt < m * n) {
            elements.push_back(matrix[i][j]);
            visted[i][j] = true;
            ++cnt;
            const int next_x = i + directions[index][0], next_y = j + directions[index][1];
            if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || visted[next_x][next_y]) {
                index = (index + 1) % 4;
            }
            i += directions[index][0];
            j += directions[index][1];
        }
        return elements;
    }
};