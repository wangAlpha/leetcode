/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insert_val) {
        auto node = new Node(insert_val);
        if (!head) {
            node->next = node;
            return node;
        }
        auto cur = head;
        while (cur->next != head) {
            auto next = cur->next;
            if (insert_val >= cur->val && insert_val <= next->val) {
                break;
            }
            if (next->val < cur->val && (insert_val <= next->val || insert_val >= cur->val)) {
                break;
            }
            cur = cur->next;
        }
        node->next = cur->next;
        cur->next = node;
        return head;
    }
};