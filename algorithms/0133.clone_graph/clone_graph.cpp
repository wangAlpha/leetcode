/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> copy_map;
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        cloneNode(node);
        for (auto &[from, to]: copy_map) {
            for (auto &next: from->neighbors) {
                to->neighbors.emplace_back(copy_map[next]);
            }
        }
        return copy_map[node];
    }
    void cloneNode(Node* node) {
        copy_map[node] = new Node(node->val);
        for (auto &neighbor: node->neighbors) {
            if (!copy_map[neighbor]) {
                cloneNode(neighbor);
            }
        }
    }
};