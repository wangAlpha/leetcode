class Solution {
public:
    int divide(int a, int b) {
        if (b == -1) {
            if (a == INT_MAX) {
                return INT_MIN;
            }
            if (a == INT_MIN) {
                return INT_MAX;
            }
            return -a;
        }
        if (b == 1) {
            return a;
        }
        if (b == 0) {
            return 0;
        }
        if (b == INT_MIN) {
            return a == INT_MIN ? 1 : 0;
        }
        int count = 0;
        const int sign = (a > 0) ^ (b > 0) ? -1 : 1;
        if (a == INT_MIN) {
            a += abs(b);
            count += 1;
        }
        if (a < 0) {
            a = -a;
        }
        if (b < 0) {
            b = -b;
        }
        while (a >= b) {
            int base = 1;
            int divisor = b;
            while (a - divisor >= divisor) {
                divisor <<= 1;
                base <<= 1;
            }
            
            count += base;
            a -= divisor;
        }
        return sign > 0 ? count: -count;
    }
};