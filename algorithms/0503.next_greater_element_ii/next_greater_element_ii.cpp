class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        const int len = nums.size();
        vector<int> greater_nums(len, -1);
        stack<int> mono_stack;
        stack<int> index_stack;
        for (int i = 0; i < len; ++i) {
            nums.push_back(nums[i]);
        }
        for (int i = 0; i < nums.size(); ++i) {
            const int &n = nums[i];
            while (!mono_stack.empty() && n > mono_stack.top()) {
                mono_stack.pop();
                const int prev_index = index_stack.top() % len; index_stack.pop();
                greater_nums[prev_index] = n;
            }
            mono_stack.push(n); index_stack.push(i);
        }
        return greater_nums;
    }
};