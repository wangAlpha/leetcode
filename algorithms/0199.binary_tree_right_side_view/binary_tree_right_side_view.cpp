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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> first, second;
        if (root != nullptr) {
            first.push(root);
        }
        while (!first.empty()) {
            int view = 0;
            while (!first.empty()) {
                auto node = first.front(); first.pop();
                view = node->val;
                if (node->left != nullptr) {
                    second.push(node->left);
                }
                if (node->right != nullptr) {
                    second.push(node->right);
                }
            }
            result.emplace_back(view);
            first.swap(second);
        }
        return result;
    }
};