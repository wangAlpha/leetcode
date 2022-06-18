class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        double ans = 1;
        const double sign = n > 0 ? 1 : -1;
        int64_t N = n;
        N = N > 0 ? N : -N;
        while (N) {
            if (N & 0x1 == 0x1) {
                ans *= x;
            }
            x *= x;
            N >>= 1;
        }
        return sign == 1 ? ans : 1/ans;
    }
};