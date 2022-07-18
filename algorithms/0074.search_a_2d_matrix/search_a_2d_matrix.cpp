class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        const int m = matrix.size();
        int x = 0, y = matrix[0].size() - 1;
        while (x < m && y >= 0) {
            if (matrix[x][y] == target) {
                return true;
            }
            if (matrix[x][y] < target) {
                ++x;
            } else {
                --y;
            }
        }
        return false;
    }
};