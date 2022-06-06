class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> nums_counter;
        for (const int &n: nums) {
            if(++nums_counter[n] == 3) {
                nums_counter.erase(n);
            }
        }
        return nums_counter.begin()->first;
    }
};