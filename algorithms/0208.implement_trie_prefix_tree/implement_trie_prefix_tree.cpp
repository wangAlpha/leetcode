class Trie {
public:
    Trie() : children_(26), isEnd_(false) {}
    
    void insert(const string &word) {
        Trie* node = this;
        for (const char &ch: word) {
            const char c = ch - 'a';
            if (node->children_[c] == nullptr) {
                node->children_[c] = new Trie();
            }
            node = node->children_[c];
        }
        node->isEnd_ = true;
    }
    
    bool search(string word) {
        auto node = searchPrefix(word);
        return node != nullptr && node->isEnd_;
    }
    
    bool startsWith(const string &prefix) {
        return searchPrefix(prefix) != nullptr;
    }
private:
    Trie* searchPrefix(const string &prefix) {
        auto node = this;
        for (const char&ch: prefix) {
            const char c = ch - 'a';
            if (node->children_[c] == nullptr) {
                return nullptr;
            }
            node = node->children_[c];
        }    
        return node;
    }

    vector<Trie*> children_;
    bool isEnd_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */