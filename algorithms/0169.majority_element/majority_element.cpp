class Solution {
public:
    int majorityElement(vector<int>& nums) {
        const int len = nums.size();
        unordered_map<int, int> num_counter;
        for (const int &n: nums) {
            if (++num_counter[n] >= (len + 1)/2) {
                return n;
            }
        }
        return -1;
    }
};