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
    void traverse(TreeNode* root, string path, vector<string> &result) {
        path += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            result.emplace_back(path);
            return;
        }
        path += "->";
        if (root->left != nullptr) {
            traverse(root->left, path, result);
        }
        if (root->right != nullptr) {
            traverse(root->right, path, result);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        if (root == nullptr) {
            return result;
        }
        traverse(root, path, result);
        return result;
    }
};