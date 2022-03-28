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
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        auto left = root->left;
        auto right = root->right;
        int left_height = 0;
        int right_height = 0;
        while (left != nullptr) {
            left = left->left;
            ++left_height;
        }
        while (right != nullptr) {
            right = right->right;
            ++right_height;
        }
        if (right_height == left_height) {
            return (2 << left_height) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};