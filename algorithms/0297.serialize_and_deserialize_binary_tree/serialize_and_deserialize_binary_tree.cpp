/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans_;
        if (root == nullptr) {
            return ans_;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node) {
                ans_.append(to_string(node->val) + ' ');
                q.push(node->left);
                q.push(node->right);
            } else {
                ans_.append("# ");
            }
        }
        return ans_;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(const string& data) {
        if (data.empty()) {
            return nullptr;
        }
        istringstream sin(data);
        vector<string> level;
        string t;
        while (sin >> t) {
            level.emplace_back(t);
        }
        return buildTree(level);
    }
    TreeNode* buildTree(const vector<string>& data) {
        if (data[0] == "#") {
            return nullptr;
        }
        queue<TreeNode*> q;
        auto root = new TreeNode(stoi(data[0]));
        q.push(root);
        int cnt = 1;
        while (cnt < data.size()) {
            auto node = q.front();
            q.pop();
            if (data[cnt] != "#") {
                auto left = new TreeNode(stoi(data[cnt]));
                node->left = left;
                q.push(left);
            }
            if (cnt + 1 >= data.size()) {
                break;
            }
            if (data[cnt + 1] != "#") {
                auto right = new TreeNode(stoi(data[cnt + 1]));
                node->right = right;
                q.push(right);
            }
            cnt += 2;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));