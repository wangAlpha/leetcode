class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp = {{0, -1}};
        int ans = 0;
        int counter = 0;
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] == 0? ++counter : --counter;
            if (mp.find(counter) == mp.end()) {
                mp[counter] = i;
            } else {
                ans = max(ans, i - mp[counter]);
            }
        }
        return ans;
    }
};