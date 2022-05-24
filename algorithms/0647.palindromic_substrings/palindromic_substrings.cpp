class Solution {
public:
    int countSubstrings(const string& s) {
        int count = 0;
        for (int i = 0; i < s.length(); ++i) {
            count += extendSubstrings(s, i, i);
            count += extendSubstrings(s, i, i + 1);
        }
        return count;
    }
    int extendSubstrings(const string& s, int lo, int hi) {
        int count = 0;
        while (lo >= 0 && hi < s.length() && s[lo] == s[hi]) {
            --lo;
            ++hi;
            ++count;
        }
        return count;
    }
};