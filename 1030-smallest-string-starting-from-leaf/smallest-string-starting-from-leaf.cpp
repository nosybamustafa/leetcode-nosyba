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
  string smallestFromLeaf(TreeNode* root) {
    string ans;
    dfs(root, "", ans);
    return ans;
  }

 private:
  void dfs(TreeNode* node, string&& path, string& ans) {
    if (node == nullptr) return;

    path.push_back(char(node->val + 'a'));

    if (!node->left && !node->right) {
      reverse(path.begin(), path.end());
      if (ans.empty() || path < ans) ans = path;
      reverse(path.begin(), path.end());  // Restore path
    }

    dfs(node->left, move(path), ans);
    dfs(node->right, move(path), ans);
    path.pop_back();
  }
};
