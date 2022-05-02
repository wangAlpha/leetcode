class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        vector<vector<int>> merge_intervals;
        for (int i = 0; i < intervals.size(); ++i) {
            int first = intervals[i][0];
            int last = intervals[i][1];
            while (i + 1 < intervals.size() && last >= intervals[i + 1][0]) {
                last = max(intervals[i + 1][1], last);
                ++i;
            }
            merge_intervals.push_back({first, last});
        }
        return merge_intervals;
    }
};