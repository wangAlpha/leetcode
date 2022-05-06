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
    int rob(TreeNode* root) {
        const auto result = robTree(root);
        return max(result[0], result[1]);
    }
    vector<int> robTree(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }
        const auto left = robTree(root->left);
        const auto right = robTree(root->right);
        // 偷root
        const int value1 = root->val + left[0] + right[0];
        // 不偷root
        const int value2 = max(left[0], left[1]) + max(right[0], right[1]);
        return {value2, value1};
    }
};