class Solution {
 public:
  auto depth(TreeNode* root) -> int {
    if (not root) return 0;
    return max(depth(root->left), depth(root->right)) + 1;
  }

  auto diameterOfBinaryTree(TreeNode* root) -> int {
    if (not root) return 0;
    if (not root->left and not root->right) return 0;

    const auto diameter_l = diameterOfBinaryTree(root->left);
    const auto diameter_r = diameterOfBinaryTree(root->right);

    return max(max(diameter_l, diameter_r),
               depth(root->left) + depth(root->right));
  }
};

class Solution {
 private:
  auto depth(TreeNode* const node, int& diameter) -> int {
    if (not node) return 0;

    auto left = depth(node->left, diameter);
    auto right = depth(node->right, diameter);

    if (left + right > diameter) diameter = left + right;
    return max(left, right) + 1;
  }

 public:
  auto diameterOfBinaryTree(TreeNode* const root) -> int {
    auto diameter = 0;
    height(root, diameter);
    return diameter;
  }
};