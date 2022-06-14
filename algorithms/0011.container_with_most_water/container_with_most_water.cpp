class Solution {
public:
    int maxArea(const vector<int>& heights) {
        int area = 0;
        int lo = 0, hi = heights.size() - 1;
        while (lo < hi) {
            const int height = min(heights[lo], heights[hi]);
            const int width = hi - lo;
            area = max(area, height * width);
            if (heights[lo] < heights[hi]) {
                ++lo;      
            } else {
                --hi;
            }
        }
        return area;
    }
};