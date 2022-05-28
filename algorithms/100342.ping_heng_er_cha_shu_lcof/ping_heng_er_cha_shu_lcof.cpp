/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        int left = getDepth(root->left);
        if (left == -1) {
            return false;
        }
        int right = getDepth(root->right);
        if (right == -1) {
            return false;
        }
        return abs(left - right) <= 1;
    }
    int getDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = getDepth(root->left);
        if (left == -1) {
            return -1;
        }
        int right = getDepth(root->right);
        if (right == -1) {
            return -1;
        }
        return abs(left - right) > 1 ? -1 : max(left, right) + 1;
    }
};