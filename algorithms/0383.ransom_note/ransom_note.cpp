class Solution {
public:
    bool canConstruct(string &ransomNote, string &magazine) {
        int char_map[65] = {0};
        for (const char&c: magazine) {
            ++char_map[c - 'A'];
        }
        for (const char&c: ransomNote) {
            const auto i = c - 'A';
            --char_map[i];
            if (char_map[i] < 0) {
                return false;
            }
        }
        return true;
    }
};