class Solution {
public:
    bool isPalindrome(string& s) {
        bool result = true;
        int lo = 0, hi = s.length() - 1;
        while (lo < hi) {
            while (lo <= hi && !isalnum(s[lo])) {
                ++lo;
            }
            while (lo <= hi && !isalnum(s[hi])) {
                --hi;
            }
            if (lo <= hi) {
                if (isalpha(s[lo])) {
                    s[lo] = tolower(s[lo]);
                }
                if (isalpha(s[hi])) {
                    s[hi] = tolower(s[hi]);
                }
            }
            if (lo <= hi && s[lo] != s[hi]) {
                result = false;
                break;     
            }
            ++lo;
            --hi;
        }
        return result;
    }
};