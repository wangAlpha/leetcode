class Solution {
public:
    bool checkInclusion(const string &s1, const string &s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        unordered_map<char, int> ch1_counter;
        unordered_map<char, int> ch2_counter;

        const int n = s1.size();
        for (const char &c: s1) {
            ++ch1_counter[c];
        }
        for (size_t i = 0; i < n; ++i) {
            ++ch2_counter[s2[i]];
        }
        for (size_t i = n; i < s2.size(); ++i) {
            if (ch2_counter == ch1_counter) {
                return true;
            }
            const char &c = s2[i];
            const char last = s2[i - n];
            ++ch2_counter[c];
            --ch2_counter[last];
            if (ch2_counter[last] == 0) {
                ch2_counter.erase(last);
            }
        }
        return ch1_counter == ch2_counter;
    }
};