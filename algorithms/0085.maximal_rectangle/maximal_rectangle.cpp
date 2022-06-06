class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        const size_t m = matrix[0].size();
        vector<int> heights(m, 0);
        int ans = 0;
        for (const auto &line: matrix) {
            for (size_t i = 0; i < m; ++i) {
                if (line[i] == '1') {
                    ++heights[i];
                } else {
                    heights[i] = 0;
                }
            }
            ans = max(ans, maxAreaOfHeights(heights));
        }
        return ans;
    }
    int maxAreaOfHeights(vector<int>& heights) {
        heights.push_back(-1);
        const int len = heights.size();
        stack<int> s;
        int ans = 0;
        for (int i = 0; i < len; ++i) {
            while (!s.empty() && heights[i] < heights[s.top()]) {
                const int prev = s.top(); s.pop();
                const int left = s.empty() ? -1 : s.top();
                const int area = (i - left - 1) * heights[prev];
                ans = max(ans, area);
            }
            s.push(i);
        }
        heights.pop_back();
        return ans;
    }
};