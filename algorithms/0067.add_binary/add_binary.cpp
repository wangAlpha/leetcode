class Solution {
public:

    string addBinary(string &a, string &b) {
        int n = max(a.size(), b.size());
        string ans;
        int carry = 0;
        for (int i = 0; i < n; ++i) {
            int num = carry;
            if (i < a.size()) {
                num += a[a.size() - i - 1] - '0';
            }
            if (i < b.size()) {
                num += b[b.size() - i - 1] - '0';
            }
            ans.push_back(static_cast<char>(num % 2) + '0');
            carry = num / 2;
        }
        if (carry > 0) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};