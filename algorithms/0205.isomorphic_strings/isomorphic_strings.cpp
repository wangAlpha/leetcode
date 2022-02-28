class Solution {
public:
    void convertIsomorphic(string &s) {
        char s_map[256] = {0};
        int index = 1;
        for (int i = 0; i < s.size(); ++i) {
            const char &c = s[i];
            if (s_map[c] == 0) {
                s_map[c] = static_cast<char>(index);
                index += 1;
            }
            s[i] = s_map[c];
        }
    }
    bool isIsomorphic(string &s, string &t) {
        if (s.size() != t.size()) {
            return false;
        }
        convertIsomorphic(s);        
        convertIsomorphic(t);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != t[i]) {
                return false;
            }
        }
        return true;
    }
};