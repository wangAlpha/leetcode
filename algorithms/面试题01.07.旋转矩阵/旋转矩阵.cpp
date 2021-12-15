class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const size_t len = matrix[0].size();
        for (size_t i = 0; i < len; ++i) {
            for (size_t j = i + 1; j < len; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (size_t i = 0; i < len; ++i) {
            for (size_t j = 0; j < len/2; ++j) {
                swap(matrix[i][j], matrix[i][len-j-1]);
            }
        }
    }
};