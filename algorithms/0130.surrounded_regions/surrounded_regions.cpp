class Solution {
public:
    void solve(vector<vector<char>>& board) {
        const int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') {
                fill_region(board, i, 0);
            }
            if (board[i][n - 1] == 'O') {
                fill_region(board, i, n - 1);
            }
        }
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') {
                fill_region(board, 0, j);
            }
            if (board[m - 1][j] == 'O') {
                fill_region(board, m - 1, j);
            }
        }
        for (auto &line: board) {
            for (auto &e : line) {
                if (e == 'B') {
                    e = 'O';
                } else if (e == 'O') {
                    e = 'X';
                }
            }
        }
    }
    void fill_region(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O') {
            return;
        }
        board[i][j] = 'B';
        fill_region(board, i + 1, j);
        fill_region(board, i - 1, j);
        fill_region(board, i, j + 1);
        fill_region(board, i, j - 1); 
    }
};