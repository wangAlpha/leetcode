class Solution {
public:
    int maxProduct(const vector<string>& words) {
        vector<int> masks(words.size(), 0);
        for (size_t i = 0; i < words.size(); ++i) {
            const auto &word = words[i];
            for (const char &c: word) {
                masks[i] |= (1 << (c - 'a'));
            }
        } 
        size_t ans = 0;
        for (size_t i = 0; i < words.size(); ++i) {
            for (size_t j = i + 1; j < words.size(); ++j) {
                if ((masks[i] & masks[j]) == 0) {
                    ans = max(words[i].size() * words[j].size(), ans);
                }
            }
        }
        return ans;
    }
};