class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size): window_size_(size), sum_(0) { }
    
    double next(int val) {
        sum_ += val;
        window_.push_back(val);
        if (window_.size() > window_size_) {
            sum_ -= window_.front();
            window_.pop_front();
        }
        return (double)sum_/window_.size();
    }
private:
    deque<int> window_;
    int window_size_;
    int sum_;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */