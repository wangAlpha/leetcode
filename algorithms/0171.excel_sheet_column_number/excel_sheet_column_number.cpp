class Solution {
public:
    int titleToNumber(string &columnTitle) {
        int64_t ans = 0;
        int64_t n = 1;
        for (int i = columnTitle.size() - 1; i >= 0; --i) {
            const char &c = columnTitle[i];
            ans += (c - 'A' + 1) * n;
            n *= 26;
        }
        return ans;
    }
};