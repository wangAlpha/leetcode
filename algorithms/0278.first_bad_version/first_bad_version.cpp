// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1, hi = n;
        while (lo <= hi) {
            const int mi = ((hi - lo) >> 1) + lo;
            if (isBadVersion(mi)) {
                hi = mi - 1;
            } else {
                lo = mi + 1;
            }
        }
        return lo;
    }
};