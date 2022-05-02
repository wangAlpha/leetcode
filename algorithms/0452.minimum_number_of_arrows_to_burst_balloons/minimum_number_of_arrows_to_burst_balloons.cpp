class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        auto cmp = [](const auto &a, const auto &b) {
            return a[1] < b[1];
        };
        sort(points.begin(), points.end(), cmp);
        int count = 1;
        auto point = points[0][1];
        for (const auto &ballon: points) {
            if (point < ballon[0]) {
                point = ballon[1];
                ++count; 
            }
        }
        return count;
    }
};