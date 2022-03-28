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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> first, second;
        if (root != nullptr) {
            first.push(root);
        }
        while (!first.empty()) {
            vector<int> level;
            while (!first.empty()) {
                auto node = first.front(); first.pop();
                level.push_back(node->val);
                if (node->left != nullptr) {
                    second.push(node->left);
                }
                if (node->right != nullptr) {
                    second.push(node->right);
                }
            }
            first.swap(second);
            result.emplace_back(level);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};