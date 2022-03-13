class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            if (i & 0x1) {
                result[i] = result[i - 1] + 1;
            } else {
                result[i] = result[(i >> 1)];
            }
        }
        return result;
    }
};