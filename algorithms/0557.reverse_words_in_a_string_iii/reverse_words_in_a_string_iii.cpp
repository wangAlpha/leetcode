class Solution {
public:
    string reverseWords(string s) {
        s.push_back(' ');
        size_t i = 0, j = 0;
        while (i < s.size()&& j < s.size()) {
            while (s[i] == ' ') {
                ++i;
            }
            j = i;
            while (s[j] != ' ') {
                ++j;
            }
            reverse(s.begin() + i, s.begin() + j); 
            i = j;
            j += 1;
        }
        s.pop_back();
        return s;
    }
};