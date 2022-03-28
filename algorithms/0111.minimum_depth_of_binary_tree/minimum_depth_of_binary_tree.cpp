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
    int getDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int right = INT_MAX;
        int left = INT_MAX;
        if (!(root->left != nullptr && root->right == nullptr)) {
            right = getDepth(root->right);
        }
        if (!(root->left == nullptr && root->right != nullptr)) {
            left = getDepth(root->left);
        }
        return min(left, right) + 1;
    } 
    
    int minDepth(TreeNode* root) {
        return getDepth(root);
    }
};