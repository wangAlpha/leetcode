class Solution {
public:
    int maximumSwap(int num) {
        auto nums = to_string(num);
        int maxIndex = nums.size() - 1;
        vector<int> maxNums(nums.size(), 0);
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
            maxNums[i] = maxIndex;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[maxNums[i]] != nums[i]) {
                swap(nums[maxNums[i]], nums[i]);
                break;
            }
        }
        return stoi(nums);
    }
};
