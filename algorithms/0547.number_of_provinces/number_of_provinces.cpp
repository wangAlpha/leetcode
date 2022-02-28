class Solution {
public:
    void dfs(vector<vector<int>>& friends, int i, vector<bool>& visited) {
    visited[i] = true;
    for (size_t k = 0; k < friends.size(); ++k) {
        if (friends[i][k] == 1 && !visited[k]) {
        dfs(friends, k, visited);
        }
    }
    }

    int findCircleNum(vector<vector<int>>& friends) {
    int count = 0;
    vector<bool> visited(friends.size(), false);
    for (size_t i = 0; i < friends.size(); ++i) {
        if (!visited[i]) {
        dfs(friends, i, visited);
        ++count;
        }
    }
    return count;
    }
};