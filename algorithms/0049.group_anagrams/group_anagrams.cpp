class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams_map;
        for (const auto &str: strs) {
            string key(26, 0);
            for (auto &c: str) {
                ++key[c - 'a'];
            }
            anagrams_map[key].emplace_back(str);
        }
        vector<vector<string>> groups;
        for (auto &[key, values]: anagrams_map) {
            groups.emplace_back(values); 
        }
        return groups;
    }
};