class Solution {
public:
    bool isAnagram(const string &s, const string &t) {
        if (s.size() != t.size()) {
            return false;
        }
        int alpha_dict[26] = {0};
        for (const char &c: s) {
            ++alpha_dict[c - 'a'];
        }
        for (const char &c: t) {
            --alpha_dict[c - 'a'];
        }
        return all_of(begin(alpha_dict), end(alpha_dict), [](auto &c) {return c == 0;}) && s != t;
    }
};