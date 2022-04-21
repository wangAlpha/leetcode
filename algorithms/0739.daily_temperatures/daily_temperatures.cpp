class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> mono_stack;
        stack<int> index_stack;
        vector<int> days(temperatures.size(), 0);
        mono_stack.push(temperatures[0]); index_stack.emplace(0);
        for (int i = 1; i < temperatures.size(); ++i) {
            const int temperature = temperatures[i];
            while (!mono_stack.empty() && mono_stack.top() < temperature) {
                mono_stack.pop();
                const int index = index_stack.top(); index_stack.pop();
                const int day = i - index; 
                days[index] = day;
            }
            mono_stack.emplace(temperature);
            index_stack.push(i);
            
        }
        return days;
    }
};