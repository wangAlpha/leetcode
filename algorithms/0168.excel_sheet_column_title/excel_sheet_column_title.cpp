class Solution {
public:
    string convertToTitle(int columnNumber) {
        int n = columnNumber;
        string ans;
        while (n > 0) {
           n -= 1;
           int c = n % 26;
           ans.push_back((char)c + 'A'); 
           n /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};