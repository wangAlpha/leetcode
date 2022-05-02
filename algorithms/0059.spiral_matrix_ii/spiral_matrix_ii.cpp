class Solution {
public:
    vector<vector<int>> generateMatrix(const int n) {
        const int max_num = n * n;
        const int directions[4][4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
        int row = 0, col = 0, dir_index = 0;
        int cur_num = 1;
        vector<vector<int>> matrix(n, vector<int>(n));
        while (cur_num <= max_num) {
            matrix[row][col] = cur_num;
            ++cur_num;
            int nextRow = row + directions[dir_index][0], nextCol = col + directions[dir_index][1];
            if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= n || matrix[nextRow][nextCol] != 0) {
                dir_index = (dir_index + 1) % 4;
            }
            row = row + directions[dir_index][0];
            col = col + directions[dir_index][1];
        }
        return move(matrix);
    }
};