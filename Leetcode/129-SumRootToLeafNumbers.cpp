class Solution {
 private:
  int sum = 0;

 public:
  auto sumNumbers(TreeNode* const root, const int current_sum = 0) -> int {
    if (!root) return 0;

    const auto current = current_sum * 10 + root->val;
    if (!root->left and !root->right) sum += current;
    if (root->left) sumNumbers(root->left, current);
    if (root->right) sumNumbers(root->right, current);

    return sum;
  }
};