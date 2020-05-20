struct Solution {
  auto inorder(TreeNode* const root, int& k, int& result) -> void {
    if (not root) return;
    inorder(root->left, k, result);
    --k;
    if (k == 0) result = root->val;
    inorder(root->right, k, result);
  }
  auto kthSmallest(TreeNode* const root, int k) -> int {
    auto result = 0;
    inorder(root, k, result);
    return result;
  }
};