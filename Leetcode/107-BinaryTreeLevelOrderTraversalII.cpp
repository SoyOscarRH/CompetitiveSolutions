class Solution {
  auto depth(TreeNode* const root) -> int {
    if (!root) return 0;
    return max(depth(root->left), depth(root->right)) + 1;
  }

  auto levelOrder(vector<vector<int>>& answer, TreeNode* const node, const int level) {
    if (!node) return;
    answer[level].push_back(node->val);
    levelOrder(answer, node->left, level - 1);
    levelOrder(answer, node->right, level - 1);
  }

 public:
  auto levelOrderBottom(TreeNode* const root) -> vector<vector<int>> {
    const auto d = depth(root);
    auto answer = vector<vector<int>>(d, vector<int> {});
    levelOrder(answer, root, d - 1);
    return answer;
  }
};