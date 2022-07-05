class Solution {
public:
    bool isUnique(const string& astr) {
        int64_t bits = 0;
        for (const char&c: astr) {
            if ((bits & (1 << (c - 'a'))) != 0) {
                return false;
            }
            bits |= (1 << (c - 'a'));
        }
        return true;
    }
};