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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            auto node = s.top(); s.pop();
            result.push_back(node->val);
            if (node->left != nullptr) {
                s.push(node->left);
            }
            if (node->right != nullptr) {
                s.push(node->right);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};