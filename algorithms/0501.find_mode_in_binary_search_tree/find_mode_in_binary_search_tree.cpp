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
    void update(int x) {
        if (x == base_) {
            ++count_;
        } else {
            count_ = 1;
            base_ = x;
        }
        if (count_ == maxCount_) {
            answer_.push_back(base_);
        }
        if (count_ > maxCount_) {
            maxCount_ = count_;
            answer_ = vector<int> {base_};
        }
    }
    vector<int> findMode(TreeNode* root) {
        auto cur = root;
        TreeNode *pre = nullptr;
        while (cur != nullptr) {
            if (cur->left == nullptr) {
                update(cur->val);
                cur = cur->right;
            } else {
                pre = cur->left;
                while (pre->right != nullptr && pre->right != cur) {
                    pre = pre->right;
                }
                if (pre->right == nullptr) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    pre->right = nullptr;
                    update(cur->val);
                    cur = cur->right;
                }
            }
        }
        return answer_;
    }
private:
    vector<int> answer_;
    int base_ = 0;
    int count_ = 0;
    int maxCount_ = 0;
};