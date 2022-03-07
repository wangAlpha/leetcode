class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        for (const int &e: nums) {
            const int n = e > 0 ? e : -e;
            const int num = nums[n - 1] > 0 ? nums[n-1] : -nums[n-1];
            nums[n - 1] = -num;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};