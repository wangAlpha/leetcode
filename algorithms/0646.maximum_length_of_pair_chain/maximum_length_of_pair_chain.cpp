class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](auto &a, auto &b){
           return a[1] < b[1]; 
        });
        int result = 0;
        int cur = INT_MIN;
        for (const auto &pair: pairs) {
            if (cur < pair[0]) {
                cur = pair[1];
                ++result;
            }
        }
        return result;
    }
};