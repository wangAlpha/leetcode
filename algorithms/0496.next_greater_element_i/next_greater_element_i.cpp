class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> greater_nums(nums1.size(), -1);
        stack<int> mono_stack;
        unordered_map<int, int> nums1_map;
        for (int i = 0; i < nums1.size(); ++i) {
            nums1_map[nums1[i]] = i;
        }
        for (int i = 0; i < nums2.size(); ++i) {
            const int &num = nums2[i];
            while (!mono_stack.empty() && mono_stack.top() < num) {
                const int prev_index = nums1_map[mono_stack.top()]; mono_stack.pop();
                greater_nums[prev_index] = num;
            }
            if (nums1_map.find(num) != nums1_map.end()) {
                mono_stack.push(num);
            }
        }
        return greater_nums;
    }
};