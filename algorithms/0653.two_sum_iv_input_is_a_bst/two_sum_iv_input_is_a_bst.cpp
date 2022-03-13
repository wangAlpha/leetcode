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
    void traverseTree(TreeNode* root, unordered_set<int> *values)  {
        if (root == nullptr) {
            return;
        }
        values->insert(root->val);
        traverseTree(root->left, values);
        traverseTree(root->right, values);
    }
    bool findTarget(TreeNode* root, int target) {
        unordered_set<int> values;
        traverseTree(root, &values);
        for (const auto&v: values) {
            int value = target - v;
            if (values.find(value) != values.end() && value != v) {
                return true;
            }
        } 
        return false;
    }
};