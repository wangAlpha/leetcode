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
    void traverse(TreeNode* root) {
        stack<TreeNode*> s;
        int sum = 0;
        while (root != nullptr || !s.empty()) {
            while (root != nullptr) {
                s.push(root);
                root = root->right;
            }
            root = s.top(); s.pop();
            sum += root->val;
            root->val = sum;
            root = root->left;
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        traverse(root);
        return root;
    }
};