class Solution {
public:
    int hIndex(vector<int>& citations) {
        const int n = citations.size();
        int lo = 0, hi = n;
        while (lo < hi) {
            const int h = ((hi + lo) >> 1);
            if (citations[h] >= n - h) {
                hi = h;
            } else {
                lo = h + 1;
            }
        }
        return n - lo;
    }
};