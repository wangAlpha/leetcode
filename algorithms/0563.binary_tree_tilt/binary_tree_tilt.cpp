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
    int findTilt(TreeNode* root) {
        int ans = 0;
        sumOfTree(root, ans);
        return ans;
    }
    int sumOfTree(TreeNode* root, int &ans) {
        if (root == nullptr) {
            return 0;
        }
        const int left = sumOfTree(root->left, ans);
        const int right = sumOfTree(root->right, ans);
        ans += abs(left - right);
        return root->val + left + right;
    }
    
};