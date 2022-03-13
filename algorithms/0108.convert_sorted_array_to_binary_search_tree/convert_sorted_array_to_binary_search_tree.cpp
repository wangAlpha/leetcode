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
    TreeNode* buildBST(const vector<int>& nums, int lo, int hi) {
        if (lo >= hi) {return nullptr;}
        const int mi = (lo + hi) / 2;
        auto root = new TreeNode(nums[mi], nullptr, nullptr);
        root->left = buildBST(nums, lo, mi);
        root->right = buildBST(nums, mi + 1, hi);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size());
    }
};