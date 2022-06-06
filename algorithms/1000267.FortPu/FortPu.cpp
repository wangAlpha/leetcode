class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
          srand (time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool result = false;
        if (value_map_.find(val) == value_map_.end()) {
            value_map_[val] = elements_.size();
            elements_.push_back(val);
            result = true;
        }
        return result;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        bool result = false;
        if (value_map_.find(val) != value_map_.end()) {
            const int index = value_map_[val];
            const int last = elements_.back();
            elements_[index] = last;
            value_map_[last] = index;
            elements_.pop_back();
            value_map_.erase(val);
            result = true;
        }
        return result;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        const int i = rand() % elements_.size();
        return elements_[i];
    }
private:
    unordered_map<int, int> value_map_;
    vector<int> elements_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */