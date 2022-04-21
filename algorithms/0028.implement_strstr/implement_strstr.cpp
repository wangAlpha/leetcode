class Solution {
public:
    vector<int> buildNext(const string& needle) {
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
    int strStr(const string &haystack, const string &needle) {
        if (needle.empty()) {
            return 0;
        }
        const auto next = buildNext(needle);
        int j = -1;
        for (int i = 0; i < haystack.size(); ++i) {
            while (j >= 0 && haystack[i] != needle[j + 1]) {
                j = next[j];
            }
            if (haystack[i] == needle[j + 1]) {
                ++j;
            }
            if (j == (needle.size() - 1)) {
                return i - needle.size() + 1;
            }
        }
        return -1;
    }
};