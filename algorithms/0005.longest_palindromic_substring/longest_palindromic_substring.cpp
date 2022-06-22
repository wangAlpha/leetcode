class Solution {
public:
    string longestPalindrome(const string& s) {
        const int len = s.length();
        int start = 0, end = 0;
        for (int i = 0; i < len; ++i) {
            auto [lo1, hi1] = expandAroundCenter(s, i, i);
            auto [lo2, hi2] = expandAroundCenter(s, i, i + 1);
            if (hi1 - lo1 > end - start) {
                start = lo1;
                end = hi1;
            }
            if (hi2 - lo2 > end - start) {
                start = lo2;
                end = hi2;
            }
        }
        return s.substr(start, end - start + 1);
    }
    pair<int, int> expandAroundCenter(const string& s, int lo, int hi) {
        const int len = s.length();
        while (lo >= 0 && hi <= len && s[lo] == s[hi]) {
            --lo;
            ++hi;
        }
        return {lo + 1, hi - 1};
    }
};