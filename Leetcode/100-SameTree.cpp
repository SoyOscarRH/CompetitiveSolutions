struct Solution {
  auto isSameTree(TreeNode* const p, TreeNode* const q) -> bool {
    if (not p and not q) return true;
    if (not p or not q) return false;
    if (p->val != q->val) return false;

    return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
  }
};