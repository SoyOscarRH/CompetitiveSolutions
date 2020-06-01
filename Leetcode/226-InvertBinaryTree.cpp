struct Solution {
  TreeNode* invertTree(TreeNode* const root) {
    if (not root) return nullptr;
    invertTree(root->left);
    invertTree(root->right);
    swap(root->left, root->right);

    return root;
  }
};