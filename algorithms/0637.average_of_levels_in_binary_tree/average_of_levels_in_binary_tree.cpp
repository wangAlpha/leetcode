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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> first, second;
        if (root != nullptr) {
            first.push(root);
        }
        while (!first.empty()) {
            double sum = 0;
            double len = 0;
            while (!first.empty()) {
                auto node = first.front(); first.pop();
                sum += node->val;
                ++len;
                if (node->left != nullptr) {
                    second.push(node->left);
                }
                if (node->right != nullptr) {
                    second.push(node->right);
                }
            }
            first.swap(second);
            result.emplace_back(sum/len);
        }
        return result;
    }
};