class Solution {
  auto traverse(TreeNode* const root, const int depth, vector<vector<int>>& result) -> void {
    if (not root) return;
    if (result.size() == depth) result.emplace_back();

    if (depth % 2 == 0) result[depth].push_back(root->val);
    else result[depth].insert(begin(result[depth]), root->val);

    traverse(root->left, depth + 1, result);
    traverse(root->right, depth + 1, result);
  }

 public:
  auto zigzagLevelOrder(TreeNode* const root) -> vector<vector<int>> {
    auto result = vector<vector<int>> {};
    traverse(root, 0, result);
    return result;
  }
};