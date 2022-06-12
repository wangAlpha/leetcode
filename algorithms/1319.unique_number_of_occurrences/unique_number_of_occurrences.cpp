class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> num_counter;
        for (const int &n: arr) {
            ++num_counter[n];
        }
        unordered_set<int> num_set;
        for (const auto &[n, count]: num_counter) {
            if (num_set.find(count) != num_set.end()) {
                return false;
            }
            num_set.insert(count);
        }
        return true;
    }
};