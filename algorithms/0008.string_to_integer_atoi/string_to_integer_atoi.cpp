class Solution {
public:
    int myAtoi(const string& s) {
        int64_t ans = 0;
        size_t i = 0;
        const size_t len = s.length();
        while (s[i] == ' ' && i < len) {
            ++i;
        }
        int sign = 1;
        if (i < len) {
            if (s[i] == '-') {
                sign = -1;
                ++i;
            } else if (s[i] == '+') {
                ++i;
            }
        }
        while (i < len && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0') * sign;
            if (ans >= INT_MAX) {
                return INT_MAX;
            }
            if (ans <= INT_MIN) {
                return INT_MIN;
            }
            ++i;
        }
        return ans;
    }
};