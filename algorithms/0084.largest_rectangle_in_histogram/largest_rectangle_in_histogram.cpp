class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(-1);
        const int len = heights.size();
        int ans = 0;
        for (int i = 0; i < len; ++i) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                const int prev = s.top(); s.pop();
                const int left = s.empty() ? -1 : s.top();
                ans = max(ans, (i - left - 1) * heights[prev]);
            }
            s.push(i);
        }
        return ans;
    }
};