class Solution {
  int maxToRoot(TreeNode* const root, int& general_result) {
    if (not root) return 0;
    auto left = maxToRoot(root->left, general_result);
    auto right = maxToRoot(root->right, general_result);

    if (left < 0) left = 0;
    if (right < 0) right = 0;

    auto best_with_as_center = left + right + root->val;
    general_result = max(best_with_as_center, general_result);

    auto best_with_as_element = root->val + max(left, right);
    return best_with_as_element;
  }

 public:
  auto maxPathSum(TreeNode* root) -> int {
    auto general_result = INT_MIN;
    maxToRoot(root, general_result);
    return general_result;
  }
};