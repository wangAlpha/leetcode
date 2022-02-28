class Solution {
public:
    vector<int> partitionLabels(const string &s) {
        vector<int> result;
        unordered_set<char> alpha;
        unordered_map<char, int> alpha_count;
        for (const char &c: s) {
            alpha_count[c] += 1;
        }
        int count = 0;
        for (const char &c: s) {
            alpha.insert(c);
            count += 1;
            alpha_count[c] -= 1;
            if (alpha_count[c] == 0) {
                alpha.erase(c);
                if (alpha.empty()) {
                    result.push_back(count);
                    count = 0;
                }
            }
        }
        return result;
    }
};