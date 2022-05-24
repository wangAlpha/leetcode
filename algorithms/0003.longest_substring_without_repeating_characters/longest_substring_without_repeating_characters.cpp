class Solution {
public:
    int lengthOfLongestSubstring(const string &s) {
        int ans = 0;
        unordered_map<char, int> alpha_count;
        int count = 0;
        int left = 0, right = 0;
        while (right < s.size()) {
            const char &c = s[right++];
            alpha_count[c] += 1;
            count += 1;
            if (alpha_count[c] == 1) {
                ans = max(ans, count);
            } else {
                while (alpha_count[c] == 2 && left <= right) {
                    alpha_count[s[left++]] -= 1;
                    count -= 1;
                }
            }
        }
        return ans;
    }
};