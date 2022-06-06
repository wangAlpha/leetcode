class Solution {
public:
    int subarraySum(const vector<int>& nums, int k) {
        unordered_map<int, int> prefix_map = {{0, 1}};
        int counter = 0;
        int sum = 0;
        for (const auto &n: nums) {
            sum += n;
            const auto it = prefix_map.find(sum - k);
            if (it != prefix_map.end()) {
                counter += it->second;
            }
            ++prefix_map[sum];
        }
        return counter;
    }
};