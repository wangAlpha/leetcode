/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        queue<TreeNode*> first;
        vector<vector<int>> result;
        first.push(root);
        bool lr = true;
        while (!first.empty()) {
            int size = first.size();
            vector<int> level(size, 0);
            while (size--) {
                auto node = first.front(); first.pop();
                level[lr ? level.size() - size - 1: size] = node->val;
                if (node->left != nullptr) {
                    first.push(node->left);
                }
                if (node->right != nullptr) {
                    first.push(node->right);
                }
            }
            result.emplace_back(level);
            lr = (!lr);
        } 
        return result;
    }
};