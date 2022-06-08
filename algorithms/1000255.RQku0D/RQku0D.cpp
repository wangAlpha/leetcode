class Solution {
public:
    bool validPalindrome(const string& s) {
        return isPalindrome(s, 0, s.size() - 1, false);
    }
    bool isPalindrome(const string& s, int lo, int hi, int once) {
        if (lo >= hi) {
            return true;
        }
        while (lo < hi) {
            if (s[lo] != s[hi] ) {
                if (!once) {
                    return isPalindrome(s, lo + 1, hi, true) || isPalindrome(s, lo, hi - 1, true);
                } else {
                    return false;
                }
            }
            ++lo;
            --hi;
        }
        return true;
    }
};