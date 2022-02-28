#include <unordered_map>
#include <list>

// struct Node {
//     int key;
//     int value;
//     Node *next;
//     explicit Node(int k, int v, Node*next):key(k), value(v), next(next){}
// };

// struct LinkList {
//     Node *begin = nullptr;
//     Node *end = nullptr;
//     LinkList(){begin = end;end=nullptr;}
//     Node * Insert(std::pair<int, int> node) {
//         auto new_node = new Node{node.first, node.second, nullptr};
//         end = new_node;
//         return end;
//     }
//     void Remove(Node *node){
//         if (node->next == nullptr){
//             auto b = begin;
//             while (node != b->next){b = b->next;}
//             node = 
//         }
//     }
// }

class LRUCache {
public:
    LRUCache(const int capacity) : num_pages_(capacity) { }
    
    int get(int key) {
        if (table_pages_.find(key) == table_pages_.end()) {
            return -1;
        }
        auto it = table_pages_[key];
        pages_.splice(pages_.end(), pages_, it);
        return it->second;
    }
    
    void put(int key, int value) {
        if (table_pages_.find(key) == table_pages_.end()) {
            if (table_pages_.size() == num_pages_) {
                auto kv = pages_.front();
                pages_.pop_front();
                table_pages_.erase(kv.first);
            }
            table_pages_[key] = pages_.insert(pages_.end(), std::make_pair(key, value));
            return;
        }
        auto it = table_pages_[key];
        it->second = value;
        pages_.splice(pages_.end(), pages_, it);
    }

private:
    const int num_pages_;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator > table_pages_;
    std::list<std::pair<int, int>> pages_;
};