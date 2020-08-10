class Solution {
  auto pathSumWorker(TreeNode* const root, const int sum, int& ways, const bool parent_used) -> void {
    if (not root) return;
    if (sum == root->val) ways++;

    pathSumWorker(root->left, sum - root->val, ways, true);
    pathSumWorker(root->right, sum - root->val, ways, true);

    if (not parent_used) {
      pathSumWorker(root->left, sum, ways, false);
      pathSumWorker(root->right, sum, ways, false);
    }
  }

 public:
  auto pathSum(TreeNode* const root, const int sum) -> int {
    auto num_of_ways = 0;
    pathSumWorker(root, sum, num_of_ways, false);
    return num_of_ways;
  }
};