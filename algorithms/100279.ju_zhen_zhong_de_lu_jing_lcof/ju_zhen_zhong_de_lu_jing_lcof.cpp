class Solution {
public:
    bool exist(vector<vector<char>>& board, const string& word) {
        const int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0] && hasPath(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool hasPath(vector<vector<char>>& board, const string& word, int i, int j, int k) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || k < 0 || k >= word.size() || word[k] != board[i][j]) {
            return false;
        }
        board[i][j] = '\0';
        if (k + 1 == word.size()) {
            return true;
        }
        bool result = hasPath(board, word, i + 1, j, k + 1)
                    || hasPath(board, word, i - 1, j, k + 1)
                    || hasPath(board, word, i, j + 1, k + 1)
                    || hasPath(board, word, i, j - 1, k + 1);
        board[i][j] = word[k];
        return result;
    }
};