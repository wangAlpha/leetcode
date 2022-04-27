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
    TreeNode* buildTree(const vector<int>& preorder, int lo, int hi, const vector<int>&inorder, int left, int right) {
        if (hi < lo) {
            return nullptr;
        }
        auto root = new TreeNode(preorder[lo]);
        const int mi = index_dict_[preorder[lo]];
        const int size = mi - left;
        root->left = buildTree(preorder, lo + 1, lo + size, inorder, left, mi - 1);
        root->right = buildTree(preorder, lo + size + 1, hi, inorder, mi + 1, right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            index_dict_[inorder[i]] = i;
        } 
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
private:
    unordered_map<int, int> index_dict_;
};