class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> num_counter;
        for (const auto& n: nums1) {
            ++num_counter[n];
        }
        for (const auto& n: nums2) {
            auto &counter = num_counter[n];
            if (counter > 0) {
                ans.push_back(n);
                --counter;
            }
        }
        return ans;
    }
};