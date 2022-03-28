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
    void searchPath(TreeNode* root, int targetSum, int sum) {
        path.push_back(root->val);
        sum += root->val;
        if (sum == targetSum && root->left == nullptr && root->right == nullptr) {
            paths.push_back(path);
        }
        if (root->left != nullptr) {
            searchPath(root->left, targetSum, sum);
            path.pop_back();
        }
        if (root->right != nullptr) {
            searchPath(root->right, targetSum, sum);
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return paths;
        }
        searchPath(root, targetSum, 0);
        return paths;
    }
private:
    vector<vector<int>> paths;
    vector<int> path;
};