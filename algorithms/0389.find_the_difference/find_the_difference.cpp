class Solution {
public:
    char findTheDifference(const string& s, const string& t) {
        char c = t.back();
        for (size_t i = 0; i < s.size(); ++i) {
            c ^= (s[i] ^ t[i]);
        }
        return c;
    }
};