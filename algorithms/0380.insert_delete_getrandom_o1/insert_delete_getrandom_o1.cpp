class RandomizedSet {
public:
    RandomizedSet() {
        srand (time(NULL));
    }
    
    bool insert(int val) {
        bool result = false;
        if (!list_map_.count(val)) {
            list_.push_back(val);
            list_map_[val] = list_.size() - 1;
            result = true;
        }
        return result;
    }
    
    bool remove(int val) {
        bool result = false;
        if (list_map_.count(val)) {
            const int index = list_map_[val];
            const int last = list_.back();
            list_[index] = last;
            list_.pop_back();
            list_map_[last] = index;
            list_map_.erase(val);
            result = true;;
        }
        return result;
    }
    
    int getRandom() {
        int index = rand() % list_.size();
        return list_[index];
    }
private:
    vector<int> list_;
    unordered_map<int, int> list_map_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */