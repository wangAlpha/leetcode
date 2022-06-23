class Solution {
public:
    int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) {
        const size_t len = gas.size();
        int cur_sum = 0, sum = 0;
        size_t it = 0;
        for (size_t i = 0; i < len; ++i) {
            const int diff = gas[i] - cost[i];
            cur_sum += diff;
            sum += diff;
            if (cur_sum < 0) {
                cur_sum = 0;
                it = i + 1;
            }
        }
        if (sum < 0) {
            return -1;
        }
        return it;
    }
};