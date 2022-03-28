/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<Node*> first, second;
        if (root != nullptr) {
            first.push(root);
        }
        while (!first.empty()) {
            vector<int> level;
            while (!first.empty()) {
                auto node = first.front(); first.pop();
                level.push_back(node->val);
                for (auto &child: node->children) {
                    if (child != nullptr) {
                        second.push(child);
                    }
                }
            }
            first.swap(second);
            result.emplace_back(level);
        }
        return result;
    }
};