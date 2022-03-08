class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        vector<pair<int, int>> num_counter;
        unordered_map<int, int> num_map;
        for (const int &n: nums) {
            num_map[n] += 1;
        }
        for (const auto &[k, v]: num_map) {
            num_counter.emplace_back(make_pair(k, v));
        }
        auto cmp = [](const auto &a, const auto &b) { return a.second < b.second; };
        make_heap(num_counter.begin(), num_counter.end(), cmp);
        for (int i = 0; i < k; ++i) {
            result.push_back(num_counter[0].first);
            pop_heap(num_counter.begin(), num_counter.end(), cmp);
            num_counter.pop_back();
        }
        return result;
    }
};