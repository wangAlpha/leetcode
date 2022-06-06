class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        const size_t n = matrix.size(), m = (n == 0) ? 0 : matrix[0].size();
        integral_ = move(vector(n + 1, vector<int>(m + 1, 0)));
        for (size_t i = 1; i <= n; ++i) {
            for (size_t j = 1; j <= m; ++j) {
                integral_[i][j] = matrix[i - 1][j - 1] + integral_[i - 1][j] + integral_[i][j - 1]  - integral_[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return integral_[row2 + 1][col2 + 1] - integral_[row2 + 1][col1] - integral_[row1][col2 + 1] + integral_[row1][col1];
    }
private:
    vector<vector<int>> integral_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */