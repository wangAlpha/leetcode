class Solution {
public:
    bool exist(vector<vector<char>>& board, string& word) {
        const int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0] && dfs(board, i, j, word, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, int i, int j, string& word, size_t k, vector<vector<bool>>& visited) {
        if (k >= word.size()) {
            return true;
        }
        const int m = board.size(), n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || board[i][j] != word[k]) {
            return false;
        }
        visited[i][j] = true;
        bool ret = dfs(board, i + 1, j, word, k + 1, visited)
                    || dfs(board, i - 1, j, word, k + 1, visited)
                    || dfs(board, i, j + 1, word, k + 1, visited)
                    || dfs(board, i, j - 1, word, k + 1, visited);
        visited[i][j] = false;
        return ret;
    }
};