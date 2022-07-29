class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        if (array.size() < 2) {
            return {-1, -1};
        }
        const int len = array.size();
        int left = -1, right = -1;
        int curMax = INT_MIN, curMin = INT_MAX;
        for (int i = 0; i < len; ++i) {
            if (array[i] < curMax) {
                left = i;
            } else {
                curMax = array[i];
            }
        }
        for (int i = len - 1; i >= 0; --i) {
            if (array[i] > curMin) {
                right = i;
            } else {
                curMin = array[i];
            }
        }
        return {right, left};
    }
};