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
    int getMinimumDifference(TreeNode* root) {
        int result = INT_MAX;
        stack<TreeNode*> s;
        TreeNode *cur = root;
        TreeNode *pre = nullptr;
        while (!s.empty() || cur ) {
            while (cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top(); s.pop();
            if (pre != nullptr) {
                result = min(result, cur->val - pre->val);
            }
            pre = cur;
            cur = cur->right;
        }
        return result;
    }
};