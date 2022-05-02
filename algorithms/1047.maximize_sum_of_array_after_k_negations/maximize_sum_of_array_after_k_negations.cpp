class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        auto cmp = [](const int &a, const int &b) {
            return abs(a) > abs(b);
        };
        sort(nums.begin(), nums.end(), cmp);
        for (auto &n: nums) {
            if (n < 0 && k > 0) {
                n = -n; 
                --k;
            }
            if (k == 0) {
                break;
            }
        }
        if (k & 0x1 == 0x1) {
            nums.back() = -nums.back();
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};