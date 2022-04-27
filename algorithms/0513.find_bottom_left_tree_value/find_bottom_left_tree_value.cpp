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
    int findBottomLeftValue(TreeNode* root) {
        if (!root) {
            return 0;
        }
        queue<TreeNode*> first, second;
        first.push(root);
        int value = 0;
        while (!first.empty()) {
            value = first.front()->val;
            while (!first.empty()) {
                auto node = first.front(); first.pop();
                if (node->left) {
                    second.push(node->left);
                }
                if (node->right) {
                    second.push(node->right);
                }
            }
            first.swap(second);
        }
        return value;
    }
};