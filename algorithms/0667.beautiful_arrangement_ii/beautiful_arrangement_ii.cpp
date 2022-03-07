class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result(n);
        for (int i = 0; i < n - k - 1; ++i) {
            result[i] = i + 1;
        }
        int left = n - k;
        int right = n;
        int j = 0;
        for (int i = n - k - 1; i < n; ++i) {
            if (j % 2 == 0) {
                result[i] = left;
                left += 1;
            } else {
                result[i] = right;
                right -= 1;
            } 
            j += 1;
        }
        return result;
    }
};