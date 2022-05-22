class Solution {
public:
    int findShortestSubArray(const vector<int>& nums) {
        unordered_map<int, int> degrees;
        unordered_map<int, vector<size_t>> nums_index;
        int ans = INT_MAX;
        int max_counter = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            const int &n = nums[i];
            degrees[n] += 1;
            max_counter = max(max_counter, degrees[n]);
            nums_index[n].push_back(i);
        }
        for (const auto &[key, count]: degrees) {
            if (count == max_counter) {
                const int len = nums_index[key].back() - nums_index[key].front() + 1;
                ans = min(len, ans);
            }
        }
        return ans;
    }
};