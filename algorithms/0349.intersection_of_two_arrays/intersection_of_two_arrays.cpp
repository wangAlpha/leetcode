class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            nums1.swap(nums2);
        }
        vector<int> ans;
        unordered_set<int> set1(nums1.begin(), nums1.end());
        for (const auto& n: nums2) {
            if (set1.find(n) != set1.end()) {
                ans.push_back(n);
                set1.erase(n);
            }
        }
        return ans;
    }
};