class NumArray {
public:
    NumArray(vector<int>& nums): sum_(nums.size() + 1, 0) {
        partial_sum(nums.begin(), nums.end(), sum_.begin() + 1);
    }
    
    void update(int index, int val) {
        const int delta = val - (sum_[index + 1] - sum_[index]);
        for_each(sum_.begin() + index + 1, sum_.end(), [&](auto &e) { e += delta; });
    }
    
    int sumRange(int left, int right) {
        return sum_[right + 1] - sum_[left];
    }
private:
    vector<int> sum_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */