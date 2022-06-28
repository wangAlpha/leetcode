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
    int kthSmallest(TreeNode* root, int k) {
            int val = 0;
            traversal(root, k, val);
            return val;
    }
    void traversal(TreeNode* root, int &k, int &val) {
        if (root) {
            traversal(root->left, k, val);
            if (--k == 0) {
                val = root->val;
                return;
            }
            traversal(root->right, k, val);
        }
    }
};