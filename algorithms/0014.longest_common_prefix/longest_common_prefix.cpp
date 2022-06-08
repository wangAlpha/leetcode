class Solution {
public:
    string longestCommonPrefix(const vector<string>& strs) {
        string ans;
        size_t len = INT_MAX;
        for (const auto &str: strs) {
            len = min(len, str.length());
        }
        for (size_t i = 0; i < len; ++i) {
            for (size_t j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != strs[j - 1][i]) {
                    goto done;
                }
            }
            ans.push_back(strs[0][i]);
        }
done:
        return ans;
    }
};