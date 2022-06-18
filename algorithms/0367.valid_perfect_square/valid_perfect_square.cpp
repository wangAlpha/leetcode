class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) {
            return true;
        }
        int64_t number = num;
        int64_t lo = 1, hi = number/2;
        while (lo <= hi) {
            const int64_t mi = (hi - lo) / 2+ lo;
            const int64_t result = mi * mi;
            if (result == number) {
                return true;
            } else if (result < number) {
                lo = mi + 1;
            } else {
                hi = mi - 1;
            }
        }
        return false;
    }
};