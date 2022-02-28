class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        int s_map[256] = {0};
        int t_map[256] = {0};
        for (const char &c: s) {
            s_map[c] += 1;
        }
        for (const char &c: t) {
            t_map[c] += 1;
        }
        for (int i = 0; i < 256; ++i) {
            if (s_map[i] != t_map[i]) {
                return false;
            }
        }
        return true; 
    }
};