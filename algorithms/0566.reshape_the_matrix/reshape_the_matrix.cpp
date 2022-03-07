class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (mat.empty() || mat[0].size() * mat.size() != r * c) {
            return mat;
        }
        vector<vector<int>> result;
        vector<int> line;
        int count = 0;
        for (const auto&v: mat) {
            for (const int &n: v) {
                line.push_back(n);
                if (line.size() == c) {
                    result.push_back(line);
                    line.clear();
                }
            }
        }
        return result;
    }
};