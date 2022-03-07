class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, set = 0;
        int total = (n + 1) * n /2;
        vector<bool> cnts(n+1, false);
        for (const int &n: nums) {
            sum += n;
            if (!cnts[n]) {
                set += n;
            }
            cnts[n] = true;
        }
        return {sum - set, total - set};
    }
};