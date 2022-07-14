class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> timeStamps;
        for (const auto& point: timePoints) {
            const int hour = stoi(point.substr(0, 2));
            const int minute = stoi(point.substr(3, 2));
            timeStamps.push_back(hour * 60 + minute);
        }
        const int max = 24 * 60;
        sort(timeStamps.begin(), timeStamps.end());
        timeStamps.push_back(timeStamps.front());
        int ans = INT_MAX;
        for (size_t i = 1; i < timeStamps.size(); ++i) {
            const int value = abs(timeStamps[i - 1] - timeStamps[i]);
            ans = min({ans, value, abs(max - value)});
        }
        return ans;
    }
};