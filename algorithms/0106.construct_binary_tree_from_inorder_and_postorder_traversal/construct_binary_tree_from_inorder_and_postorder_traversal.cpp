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
    TreeNode* constructTree(vector<int>& inorder, vector<int>& postorder, int inBegin, int inEnd, int pBegin, int pEnd) {
        if (inorder.empty() || inEnd - inBegin <= 0) {
            return nullptr;
        }
        const int value = postorder[pEnd - 1];
        auto root = new TreeNode(value);
        if (pEnd - pBegin == 1) {
            return root;
        } 

        // --pEnd;
        int trimIndex = inBegin;
        for (; trimIndex < inEnd; ++trimIndex) {
            if (value == inorder[trimIndex]) {
                break;
            }
        }

        //         // 左中序区间，左闭右开[leftInorderBegin, leftInorderEnd)
        // int leftInorderBegin = inorderBegin;
        // int leftInorderEnd = delimiterIndex;
        // // 右中序区间，左闭右开[rightInorderBegin, rightInorderEnd)
        // int rightInorderBegin = delimiterIndex + 1;
        // int rightInorderEnd = inorderEnd;

        root->left = constructTree(inorder, postorder, inBegin, trimIndex, pBegin, pBegin + (trimIndex - inBegin));

        // // 切割后序数组
        // // 左后序区间，左闭右开[leftPostorderBegin, leftPostorderEnd)
        // int leftPostorderBegin =  postorderBegin;
        // int leftPostorderEnd = postorderBegin + delimiterIndex - inorderBegin; // 终止位置是 需要加上 中序区间的大小size
        // // 右后序区间，左闭右开[rightPostorderBegin, rightPostorderEnd)
        // int rightPostorderBegin = postorderBegin + (delimiterIndex - inorderBegin);
        // int rightPostorderEnd = postorderEnd - 1; // 排除最后一个元素，已经作为节点了
         
        root->right = constructTree(inorder, postorder, trimIndex + 1, inEnd, pBegin + (trimIndex - inBegin), pEnd-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty()) {
            return nullptr;
        }
        return constructTree(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }
};