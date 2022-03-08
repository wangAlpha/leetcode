class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> alpha_freq;
        for (const char&c: s) {
            alpha_freq[c]++ ;
        }
        sort(s.begin(), s.end(), [&](const auto &a, const auto &b){
            return alpha_freq[a] == alpha_freq[b] ? a < b : alpha_freq[a] > alpha_freq[b];
        });
        return s;
    }
};