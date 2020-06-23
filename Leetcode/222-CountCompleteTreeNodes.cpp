struct Solution {
  auto countNodes(TreeNode* const root) -> int {
    if (not root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
