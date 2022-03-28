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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> first, second;
        if (root != nullptr) {
            first.push(root);
        }
        while (!first.empty()) {
            int max_value = INT_MIN;
            while (!first.empty()) {
                auto node = first.front(); first.pop();
                max_value = max(node->val, max_value);
                if (node->left != nullptr) {
                    second.push(node->left);
                }
                if (node->right != nullptr) {
                    second.push(node->right);
                }
            }
            first.swap(second);
            result.emplace_back(max_value);
        }
        return result;
    }
};