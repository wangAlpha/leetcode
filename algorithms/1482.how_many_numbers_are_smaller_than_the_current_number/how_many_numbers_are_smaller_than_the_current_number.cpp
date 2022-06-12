class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int count_index[101] = {0};
        for (const int& n: nums) {
            ++count_index[n];
        }
        for (size_t i = 1; i < 101; ++i) {
            count_index[i] += count_index[i - 1];
        }
        vector<int> ans;
        for (const int &n: nums) {
            ans.push_back(n == 0 ? 0 : count_index[n-1]);
        }
        return ans;
    }
};