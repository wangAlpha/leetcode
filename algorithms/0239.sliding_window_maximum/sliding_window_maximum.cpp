class Solution {
public:
    class MonoQueue {
    public:
        void pop(const int value) {
            if (!data_.empty() && data_.front() == value) {
                data_.pop_front();
            }
        }
        void push(const int value) {
            while (!data_.empty() && data_.back() < value) {
                data_.pop_back();
            }
            data_.push_back(value);
        }
        int front() const {
            return data_.front();
        }
    private:
        deque<int> data_;
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonoQueue mono_queue;
        for (int i = 0; i < k; ++i) {
            mono_queue.push(nums[i]);
        }
        vector<int> max_values;
        max_values.push_back(mono_queue.front());
        for (int i = k; i < nums.size(); ++i) {
            mono_queue.pop(nums[i - k]);           
            mono_queue.push(nums[i]);
            max_values.push_back(mono_queue.front());
        }
        return max_values;
    }
};