class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0) {
            return {0};
        } else if (n == 1) {
            return {0, 1};
        }
        vector<int> result{0, 1};
        for (int i = 2; i <= n; ++i) {
            if ((i & 1) == 0) {
                result.push_back(result[(i >> 1)]);
            } else {
                result.push_back(result.back() + 1);
            }
        }
        return result;
    }
};