class Solution {
public:
    int trap(const vector<int>& height) {
        int ans = 0;
        stack<size_t> s;
        for (size_t i = 0; i < height.size(); ++i) {
            while (!s.empty() && height[i] > height[s.top()]) {
                const size_t cur = s.top(); s.pop();
                if (s.empty()) {
                    break;
                }
                const size_t left = s.top();
                const size_t right = i;
                const size_t h = min(height[left], height[right]) - height[cur];
                ans += (right - left - 1) * h;
            }
            s.emplace(i);
        }
        return ans;
    }
};