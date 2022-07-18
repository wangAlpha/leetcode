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
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return head;
        }
        unordered_map<Node*, Node*> map;
        for (auto cur = head; cur != nullptr; cur = cur->next) {
            auto node = new Node(cur->val);
            node->next = cur->next;
            node->random = cur->random;
            map[cur] = node;
        }
        for (auto cur = map[head]; cur != nullptr; cur = cur->next) {
            cur->random = map[cur->random];
            cur->next = map[cur->next];
        }
        return map[head];
    }
};