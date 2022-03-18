class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        int64_t t = 0;
        for (const int &n: nums) {
            t ^= n;
        }
        t = t & (-t);
        for (const int &n: nums) {
            if ((n & t) == 0) {
                a ^= n;
            } else {
                b ^= n;
            }
        }
        return {a, b};
    }
};