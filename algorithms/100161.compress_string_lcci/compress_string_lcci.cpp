class Solution {
public:
    string compressString(string &s) {
        s.push_back('#');
        string ans;
        size_t i = 0, start = i;
        while (i < s.size()) {
            if (s[start] != s[i]) {
                ans.push_back(s[start]);
                ans += to_string(i - start);
                start = i;
            }
            ++i;
        }
        s.pop_back();
        return ans.size() < s.size() ? ans : s;
    }
};