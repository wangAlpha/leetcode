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
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) {
            return root;
        }
        TreeNode dummyHead;
        auto node = &dummyHead;
        increasingBST(root, node);
        return dummyHead.right;
    }
    void increasingBST(TreeNode* root, TreeNode* &last) {
        if (root) {
            increasingBST(root->left, last);
            if (last != nullptr) {
                last->right = root;
                root->left = nullptr;
            }
            last = root;
            increasingBST(root->right, last);
        }
    }
};
