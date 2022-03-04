class Solution {
public:
    string addStrings(string &num1, string &num2) {
        int len = max(num1.size(), num2.size());
        string ans;
        int carry = 0;
        int n = 0;
        for (int i = 0; i < len; ++i) {
            n = carry;
            if (i < num1.size()) {
                n += static_cast<int>(num1[num1.size() - i - 1] - '0');
            }
            if (i < num2.size()) {
                n += static_cast<int>(num2[num2.size() - i - 1] - '0');
            }
            ans.push_back(static_cast<int>(n % 10 + '0'));
            carry = n / 10;
        }
        if (carry > 0) {
            // n += carry;
            ans.push_back(static_cast<int>(carry % 10 + '0'));
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};