struct Tries {
    int val = 0;
    Tries *next[26];
    Tries() {
        for (int i = 0; i < 26; ++i) {
            next[i] = nullptr;
        }
    }
};

class MapSum {
public:
    MapSum(): root_(new Tries()) { }
    
    void insert(const string &key, int val) {
        int delta = val;
        if (word_cnt_.count(key)) {
            delta -= word_cnt_[key];
        }
        word_cnt_[key] = val;
        auto node = root_;
        for (const char&c: key) {
            if (node->next[c - 'a'] == nullptr) {
                node->next[c - 'a'] = new Tries();
            }
            node = node->next[c - 'a'];
            node->val += delta;
        }
    }
    
    int sum(const string &prefix) {
        auto node = root_;
        for (const char &c: prefix) {
            if (node->next[c - 'a'] == nullptr) {
                return 0;
            }
            node = node->next[c - 'a'];
        }
        return node->val;
    }
private:
    Tries *root_;
    unordered_map<string, int> word_cnt_; 
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */