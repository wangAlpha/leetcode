class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        double x0 = x, C = x;
        while (true) {
            double xi = 0.5 * (x0 + C/x0);
            if (fabs(xi - x0) < 1e-6) {
                break;
            }
            x0 = xi;
        }
        return int(x0);
    }
};