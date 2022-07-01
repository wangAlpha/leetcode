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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) {
            return -1;
        }
        traversal(root);
        return sec_ == (int64_t)INT_MAX + 1 ? -1: sec_;
    }
    void traversal(TreeNode* root) {
        if (root) {
            const int64_t cur = root->val;
            min_ = min(min_, cur);
            if (cur != min_) {
                sec_ = min(sec_, cur);
            }
            traversal(root->left);
            traversal(root->right);
        }
    }
private:
    int64_t min_ = (int64_t)INT_MAX + 1;
    int64_t sec_ = (int64_t)INT_MAX + 1;
};