class Solution {
public:
    int longestPalindrome(const string &s) {
        int odd = 0;
        int sum = 0;
        int alpha_count[256] = {0};
        for (const char &c: s) {
            alpha_count[c] += 1;
        }
        for (const int &n: alpha_count) {
            sum += n;
            if (n & 0x1 == 1) {
                odd = 1;
                sum -= 1;
            }
        }
        return odd + sum;
    }
};