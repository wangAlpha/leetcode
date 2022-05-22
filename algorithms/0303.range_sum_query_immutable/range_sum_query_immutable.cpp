class NumArray {
    vector<int> data_;

 public:
    NumArray(const vector<int>& nums) : data_(nums.size() + 1, 0) {
        for (size_t i = 1; i < data_.size(); ++i) {
            data_[i] = (data_[i - 1] + nums[i - 1]);
        }
    }

    int sumRange(int left, int right) { return data_[right + 1] - data_[left]; }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */