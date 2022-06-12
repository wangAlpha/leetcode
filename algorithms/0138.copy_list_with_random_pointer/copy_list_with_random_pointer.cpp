/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> rnd_pointer_map_;
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        auto new_head = copyList(head);
        for (auto node = new_head; node != nullptr; node = node->next) {
            node->random = rnd_pointer_map_[node->random];
        }
        return new_head; 
    }
    Node* copyList(Node* head) {
        if (!head) {
            return nullptr;
        }
        Node dummyHead(0);
        auto tail = &dummyHead;
        for (auto node = head; node != nullptr; node = node->next) {
            auto p = new Node(node->val);
            p->random = node->random;
            tail->next = p;
            tail = tail->next;
            
            rnd_pointer_map_[node] = p;
        }
        
        return dummyHead.next;
    }
};