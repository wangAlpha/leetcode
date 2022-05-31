class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> num_counter;
        for (const int &n: nums) {
            ++num_counter[n];
            if (num_counter[n] == 3) {
                num_counter.erase(n);
            }
        }
        return num_counter.begin()->first;        
    }
};