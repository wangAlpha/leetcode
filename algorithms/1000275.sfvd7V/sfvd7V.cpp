class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for (const auto &str: strs) {
            string key(26, 0);
            for (const char &c: str) {
                ++key[c - 'a'];
            }
            mp[key].push_back(str);
        }
        for (auto &[key, values]: mp) {
            ans.emplace_back(values);
        }
        return ans;
    }
};