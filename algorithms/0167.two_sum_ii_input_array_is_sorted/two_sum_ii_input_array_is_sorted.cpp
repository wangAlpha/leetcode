class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0, hi = numbers.size() - 1;
        while (lo < hi) {
            const int sum = numbers[lo] + numbers[hi];
            if (sum == target) {
                return vector<int>{lo + 1, hi + 1}; 
            } else if (sum < target) {
                lo += 1;
            } else {
                hi -= 1;
            }
        }
        return vector<int>{-1, -1};
    }
};