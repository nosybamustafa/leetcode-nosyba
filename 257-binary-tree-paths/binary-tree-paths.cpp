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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root) return ans;
        dfs(root, to_string(root->val), ans);
        return ans;
    }

private:
    void dfs(TreeNode* node, string path, vector<string>& ans) {
        if (!node->left && !node->right) {
            ans.push_back(path);
            return;
        }
        if (node->left) {
            dfs(node->left, path + "->" + to_string(node->left->val), ans);
        }
        if (node->right) {
            dfs(node->right, path + "->" + to_string(node->right->val), ans);
        }
    }
};
