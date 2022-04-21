class Solution {
public:
    vector<int> buildNext(const string &needle) {
        vector<int> next(needle.size());
        int j = -1;
        next[0] = j;
        for (int i = 1; i < needle.size(); ++i) {
            while (j >= 0 && needle[i] != needle[j + 1]) {
                j = next[j];
            }
            if (needle[i] == needle[j + 1]) {
                ++j;
            }
            next[i] = j;
        }
        return move(next);
    }
    bool repeatedSubstringPattern(const string &s) {
        if (s.empty()) {
            return false;
        }
        const auto next = buildNext(s);
        const size_t len = s.size();
        if (next[len - 1] != -1 && len % (len - (next[len - 1] + 1)) == 0) {
            return true;
        }
        return false;
    }
};