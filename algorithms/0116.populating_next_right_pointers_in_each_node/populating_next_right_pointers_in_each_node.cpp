/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
           return root;
        }
        queue<Node*> first, second;
        first.push(root);
        while (!first.empty()) {
            Node* prev = nullptr;
            while (!first.empty()) {
                auto node = first.front(); first.pop();
                if (prev) {
                    prev->next = node;
                }
                prev = node;
                if (node->left) {
                    second.push(node->left);
                }
                if (node->right) {
                    second.push(node->right);
                }
            }
            first.swap(second);
        }
        return root;
    }
};