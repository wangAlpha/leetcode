class Solution {
public:
    string addBinary(const string& a, const string& b) {
        int sign = 0;
        string ans;
        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0) {
            const int x = i >= 0 ? a[i] - '0': 0;
            const int y = j >= 0 ? b[j] - '0': 0;
            const int sum = x + y + sign;
            // 1 + 1 = 2
            // 1 + 1 + 1 = 3
            if (sum >= 2) {
                ans.push_back(sum - 2 + '0');
                sign = 1;
            } else {
                ans.push_back(sum + '0');
                sign = 0;
            }
            i -= 1;
            j -= 1;
        }
        if (sign == 1) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};