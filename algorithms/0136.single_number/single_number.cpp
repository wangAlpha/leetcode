class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (const int &n: nums) {
            ans ^= n;
        }
        return ans;
    }
};