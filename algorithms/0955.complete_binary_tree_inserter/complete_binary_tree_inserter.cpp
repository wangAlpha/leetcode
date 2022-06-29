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
class CBTInserter {
public:
    CBTInserter(TreeNode* root) : root_(root), size_(0) {
    }
    
    int insert(int val) {
        if (root_ == nullptr) {
            root_ = new TreeNode(val);
            return val;
        }
        queue<TreeNode*> q;
        q.push(root_);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
            } else {
                node->left = new TreeNode(val);
                return node->val;
            }
            if (node->right) {
                q.push(node->right);
            } else {
                node->right = new TreeNode(val);
                return node->val;
            }
        }
        return -1;
    }    
    TreeNode* get_root() {
        return root_;
    }
    int countNode(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return countNode(root->left) + countNode(root->right) + 1;
    }
private:
    TreeNode* root_;
    int size_;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */