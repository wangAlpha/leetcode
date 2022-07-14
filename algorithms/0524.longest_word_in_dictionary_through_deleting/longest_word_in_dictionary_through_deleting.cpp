class Solution {
public:
    string findLongestWord(const string &s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](auto &a, auto &b) {
            return a.size() == b.size() ? a < b : a.size() > b.size();
        });
        const size_t n = s.size();
        for (const auto& word: dictionary) {
            const size_t m = word.size();
            size_t i = 0, j = 0;
            while (i < n && j < m) {
                if (s[i] == word[j]) {
                    ++j;
                }
                ++i;
            }
            if (j == m) {
                return word;
            }
        }
        return "";
    }
};