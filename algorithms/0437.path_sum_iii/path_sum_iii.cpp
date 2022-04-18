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
    int pathSum(TreeNode* root, int64_t curr, int targetSum) {
        if (root == nullptr) {
            return 0;
        }
        int ret = 0;
        curr += root->val;
        if (prefix_.find(curr - targetSum) != prefix_.end()) {
            ret = prefix_[curr - targetSum]; 
        }
        prefix_[curr] ++;
        ret += pathSum(root->left, curr, targetSum);
        ret += pathSum(root->right, curr, targetSum);
        prefix_[curr] --;
        return ret;
    }
    int pathSum(TreeNode* root, int targetSum) {
        prefix_[0] = 1;
        return pathSum(root, 0, targetSum);
    }
private:
    unordered_map<int, int> prefix_;
};