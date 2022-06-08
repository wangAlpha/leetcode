class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool inserted = false;
        for (auto it = intervals.begin(); it != intervals.end(); ++it) {
            if ((*it)[0] >= newInterval[0]) {
                intervals.insert(it, newInterval);
                inserted = true;
                break;
            }
        }
        if (!inserted) {
            intervals.emplace_back(newInterval);
        }
        vector<vector<int>> ans;
        ans.emplace_back(intervals[0]);
        for (size_t i = 1; i < intervals.size(); ++i) {
            auto &cur = intervals[i];
            if (ans.back()[1] >= cur[0]) {
                ans.back()[1] = max(ans.back()[1], cur[1]);
            } else {
                ans.emplace_back(cur);
            }
        }
        return ans;
    }
};