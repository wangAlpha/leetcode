class Solution {
public:
    vector<int> singleNumbers(const vector<int>& nums) {
        int result = 0;
        int a = 0;
        int b = 0;
        for (const int &n: nums) {
            result ^= n;
        }
        int div = 1;
        while ((result & div) == 0) {
            div <<= 1;
        }
        for (const int &n: nums) {
            if (div & n) {
                a ^= n;
            } else {
                b ^= n;
            }
        }
        return {a, b};
    }
};