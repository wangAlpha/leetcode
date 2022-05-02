class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        int count = 0;
        int curr = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            const auto &interval = intervals[i];
            if (curr > interval[0]) {
                ++count;
            } else {
                curr = interval[1];
            }
        }
        return count;
    }
};