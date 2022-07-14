class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const size_t m = board.size(), n = board[0].size();
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (board[i][j] != '.' && !isValid(board, i, j)) {
                    return false;
                } 
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>>& board, size_t i, size_t j) {
        const size_t m = board.size(), n = board[0].size();
        const char& c = board[i][j];
        for (size_t k = 0; k < n; ++k) {
            if (k != j && board[i][k] == c) {
                return false;
            }
        }
        for (size_t k = 0; k < m; ++k) {
            if (k != i && board[k][j] == c) {
                return false;
            }
        }
        const size_t x = (i / 3) * 3, y = (j / 3) * 3;
        for (size_t k = x; k < x + 3; ++k) {
            for (size_t kk = y; kk < y + 3; ++kk) {
                if (k != i && kk != j && board[k][kk] == c) {
                    return false;
                }
            }
        }
        return true;
    }
};