class Solution {
public:
    int compareVersion(const string& version1, const string& version2) {
        const size_t m = version1.length(), n = version2.length();
        size_t i = 0, j = 0;
        while (i < m || j < n) {
            int64_t x = 0, y = 0;
            for (; i < m && version1[i] != '.'; ++i) {
                x = x * 10 + version1[i] - '0';
            }
            for (; j < n && version2[j] != '.'; ++j) {
                y = y * 10 + version2[j] - '0';
            } 
            if (x != y) {
                return x > y ? 1 : -1;
            }
            ++i; ++j;
        }
        return 0;
    }
};