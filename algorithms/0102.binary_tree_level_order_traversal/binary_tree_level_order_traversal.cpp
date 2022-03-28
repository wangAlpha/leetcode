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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        queue<TreeNode*> first;
        queue<TreeNode*> second;
        first.push(root);
        while (!first.empty()) {
            vector<int> level;
            while (!first.empty()) {
                root = first.front(); first.pop();
                level.push_back(root->val);
                if (root->left != nullptr) {
                    second.push(root->left);
                }
                if (root->right != nullptr) {
                    second.push(root->right);
                }
            }
            first.swap(second);
            result.emplace_back(level);
        }
        return result;
    }
};