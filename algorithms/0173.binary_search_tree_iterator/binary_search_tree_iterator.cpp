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
class BSTIterator {
    TreeNode* root_;
    stack<TreeNode*> s_;
public:
    BSTIterator(TreeNode* root) : root_(root) {}
    
    int next() {
        while (root_) {
            s_.push(root_);
            root_ = root_->left;
        }
        auto node = s_.top();
        s_.pop();
        const int val = node->val;
        root_ = node->right;
        return val;
    }
    
    bool hasNext() {
        return root_ != nullptr || !s_.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */