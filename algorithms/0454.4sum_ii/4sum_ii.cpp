class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sum_map;
        for (const int &a: nums1) {
            for (const int &b: nums2) {
                ++sum_map[a + b];
            }
        }
        int count = 0;
        for (const int &c: nums3) {
            for (const int &d: nums4) {
                if (sum_map.find(0 - (c+d)) != sum_map.end()) {
                    count += sum_map[0 - (c + d)];
                }
            }
        }
        return count;
    }
};