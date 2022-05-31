class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0, hi = numbers.size() - 1;
        while (true) {
            const int sum = numbers[lo] + numbers[hi];
            if (sum < target) {
                lo += 1;
            } else if (sum > target) {
                hi -= 1;
            } else {
                return {lo, hi};
            }
        }
    }
};