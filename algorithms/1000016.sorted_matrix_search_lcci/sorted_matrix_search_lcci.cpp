class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        const int n = matrix.size(), m = matrix[0].size();
        int x = 0, y = m - 1;
        while (x < n && y >= 0) {
            if (matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] < target) {
                x += 1;
            } else {
                y -= 1;
            }
        }
        return false;
    }
};