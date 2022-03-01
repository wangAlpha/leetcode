class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int64_t reserve_n = 0;
        int64_t n = x;
        while (n > 0) {
            reserve_n *= 10;
            reserve_n += (n % 10);
            n /= 10;
        }
        return reserve_n == x;
    }
};