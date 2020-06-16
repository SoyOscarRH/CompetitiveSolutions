struct Solution {
  auto searchBST(TreeNode* const root, const int val) -> TreeNode* {
    if (root) {
      const auto current = root->val;
      if (current == val) return root;
      if (current < val) return searchBST(root->right, val);
      if (current > val) return searchBST(root->left, val);
    }

    return nullptr;
  }
};