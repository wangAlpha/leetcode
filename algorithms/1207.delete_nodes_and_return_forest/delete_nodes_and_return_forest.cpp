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
template<typename T> using HashSet = unordered_set<T>;
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        HashSet<int> to_deletes(to_delete.begin(), to_delete.end());
        helper(root, nullptr, to_deletes);
        return ans_;
    }
    TreeNode* helper(TreeNode* root, TreeNode* parent, HashSet<int>& to_deletes) {
        if (!root) {
            return root;
        }
        auto left = root->left;
        auto right = root->right;
        if (to_deletes.find(root->val) != to_deletes.end()) {
            to_deletes.erase(root->val);
            delete root;
            root = nullptr;
        } else {
            if (parent == nullptr) {
                ans_.push_back(root); 
            }
        }
        auto l = helper(left, root, to_deletes);
        auto r = helper(right, root, to_deletes);
        if (root) {
            root->left = l;
            root->right = r;
        }
        return root;
    }
private:
    vector<TreeNode*> ans_;
};