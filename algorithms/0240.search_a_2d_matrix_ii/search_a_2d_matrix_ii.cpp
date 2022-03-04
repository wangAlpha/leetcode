class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int n = matrix.size(), m = matrix[0].size();
        int x = 0, y = m - 1;
        while (x < n && y >= 0) {
            if (matrix[x][y] < target) {
                x += 1;
            } else if (matrix[x][y] > target) {
                y -= 1;
            } else {
                return true;
            }
        }
        return false;
    }
};