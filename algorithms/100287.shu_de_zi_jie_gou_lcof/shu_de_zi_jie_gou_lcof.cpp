/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr) {
            return false;
        }
        if (A->val == B->val && helper(A->left, B->left) && helper(A->right, B->right)) {
            return true;
        }

        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
    bool helper(TreeNode* A, TreeNode* B) {
        if (!B) {
            return true;
        }
        if (!A && B) {
            return false;
        }
        return A->val == B->val && helper(A->left, B->left) && helper(A->right, B->right); 
    }
};