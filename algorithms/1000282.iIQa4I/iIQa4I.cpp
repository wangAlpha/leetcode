class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int len = temperatures.size();
        stack<int> s;
        vector<int> result(temperatures.size(), 0);
        for (int i = 0; i < len; ++i) {
            const int &cur = temperatures[i];
            while (!s.empty() && temperatures[s.top()] < cur) {
                const int prev = s.top(); s.pop();
                result[prev] = i - prev;
            }
            s.push(i);
        }
        return result;
    }
};