class Solution {
public:
    string minWindow(const string& ss, const string& substr) {
        if (ss.size() < substr.size()) {
            return "";
        }
        int ss_count[128] = {0};
        int sub_count[128] = {0};
        for (const char& c: substr) {
            ++sub_count[c];
        }

        string ans;
        size_t cnt = 0;
        for (size_t i = 0, j = 0; i < ss.size(); ++i) {
            const char& c = ss[i];
            ++ss_count[c];
            if (ss_count[c] <= sub_count[c]) {
                ++cnt;
            }
            while (ss_count[ss[j]] > sub_count[ss[j]]) {
                --ss_count[ss[j]];
                ++j;
            }
            if (cnt == substr.size()) {
                if (ans.empty() || i - j + 1 < ans.size()) {
                    ans = ss.substr(j, i - j + 1);     
                }
            }
        }
        return ans;
    }
};