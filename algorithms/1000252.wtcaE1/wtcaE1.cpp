class Solution {
public:
    int lengthOfLongestSubstring(const string &s) {
        int alpha_count[256] = {0};
        int left = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            alpha_count[s[i]] += 1;
            if (alpha_count[s[i]] > 1) {
                while (left < i && alpha_count[s[i]] > 1) {
                    alpha_count[s[left]] -= 1;
                    left += 1;
                } 
            } 
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};