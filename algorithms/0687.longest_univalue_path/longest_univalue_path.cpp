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
    int ans = 0;
    int longestPath(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = longestPath(root->left);
        int right = longestPath(root->right);
        if (root->left != nullptr && root->val == root->left->val) {
            left += 1;
        } else {
            left = 0;
        }
        if (root->right != nullptr && root->val == root->right->val) {
            right += 1;
        } else {
            right = 0;
        }
        ans = max(ans, left + right);
        return max(left, right);
    }
    int longestUnivaluePath(TreeNode* root) {
        longestPath(root);
        return ans;
    }
};