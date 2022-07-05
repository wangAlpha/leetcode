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
    int maxPathSum(TreeNode* root) {
        int val = INT_MIN;
        traversal(root, val);
        return val;
    }
    int traversal(TreeNode* root, int& val) {
        if (!root) {
            return 0;
        }
        const int left = max(0, traversal(root->left, val));
        const int right = max(0, traversal(root->right, val));
        val = max({val, root->val + left + right});
        return root->val + max(left, right);
    }
private:
    int ans_ = INT_MIN;
};