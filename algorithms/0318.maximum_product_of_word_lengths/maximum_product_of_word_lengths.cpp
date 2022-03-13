class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> word_counter;
        int ans = 0;
        for (const string &word: words) {
            int mask = 0, len = word.size();
            for (const char &c : word) {
                mask |= 1 << (c - 'a');
            }
            word_counter[mask] = max(word_counter[mask], len);
            for (const auto&[h_mask, h_len]: word_counter) {
                if ((mask & h_mask) == 0x00) {
                    ans = max(ans, len * h_len);
                }
            }
        }
        return ans;
    }
};