class Solution {
public:
    vector<string> findRepeatedDnaSequences(const string& s) {
        vector<string> ans;
        unordered_map<string, int> str_counter;
        for (size_t i = 0; i < s.length(); ++i) {
            string &&substr = s.substr(i, 10);
            if (++str_counter[substr] == 2) {
                ans.emplace_back(substr);
            }
        }
        return ans;
    }
};