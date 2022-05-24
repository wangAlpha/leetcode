class Solution {
public:
    int longestConsecutive(const vector<int>& nums) {
        unordered_set<int> uniq_nums(nums.cbegin(), nums.cend());
        int ans = 0;
        while (!uniq_nums.empty()) {
            const int cur = (*uniq_nums.cbegin());
            uniq_nums.erase(cur);
            int next = cur + 1, prev = cur - 1;
            while (uniq_nums.find(next) != uniq_nums.end()) {
                uniq_nums.erase(next);
                next += 1;
            }
            while (uniq_nums.find(prev) != uniq_nums.end()) {
                uniq_nums.erase(prev);
                prev -= 1;
            }
            ans = max(ans, next - prev - 1);
        }
        return ans;
    }

};