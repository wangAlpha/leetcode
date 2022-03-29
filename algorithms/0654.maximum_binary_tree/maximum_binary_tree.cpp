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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int lo, int hi) {
        if (lo >= hi) {
            return nullptr;
        }
        int maxValueIndex = lo;
        for (int i = lo + 1; i < hi; ++i) {
            if (nums[i] > nums[maxValueIndex]) {
                maxValueIndex = i;
            }
        }
        auto root = new TreeNode(nums[maxValueIndex]);
        root->left = constructMaximumBinaryTree(nums, lo, maxValueIndex);
        root->right = constructMaximumBinaryTree(nums, maxValueIndex + 1, hi);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums, 0, nums.size());
    }
};