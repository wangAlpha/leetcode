/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* getMedian(ListNode* left, ListNode* right) {
        auto fast = left;
        auto slow = left;
        while (fast != right && fast->next != right) {
            fast = fast->next;
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
    TreeNode* buildBST(ListNode* left, ListNode* right) {
        if (left == right) {
            return nullptr;
        }
        auto mi = getMedian(left, right);
        auto root = new TreeNode(mi->val);
        root->left = buildBST(left, mi);
        root->right = buildBST(mi->next, right); 
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return buildBST(head, nullptr);        
    }
};