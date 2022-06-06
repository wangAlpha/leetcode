class Solution {
public:
    Solution(vector<int>& weights): weights_(move(weights)) {
        partial_sum(weights_.begin(), weights_.end(), weights_.begin());
    }
    
    int pickIndex() {
        const int n = rand() % weights_.back() + 1;
        return lower_bound(weights_.begin(), weights_.end(), n) - weights_.begin();
    }
private:
    vector<int> weights_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */