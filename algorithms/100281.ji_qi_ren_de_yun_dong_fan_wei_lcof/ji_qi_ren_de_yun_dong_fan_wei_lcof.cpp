class Solution {
public:
    int movingCount(int m, int n, int k) {
        int ans = 0; 
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return countMoveRange(m, n, 0, 0, k, visited);
    }
    int countMoveRange(int m, int n, int i, int j, int k, vector<vector<bool>>& visited) {
        if (i < 0 || i >= m || j < 0 || j >= n || getSum(i) + getSum(j) > k || visited[i][j]) {
            return 0;
        }
        visited[i][j] = true;
        return 1 + countMoveRange(m, n, i + 1, j, k, visited) 
                + countMoveRange(m, n, i - 1, j, k, visited)
                + countMoveRange(m, n, i, j + 1, k, visited)
                + countMoveRange(m, n, i, j - 1, k, visited);
    }
    int getSum(int n) {
        int sum = 0;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
};
