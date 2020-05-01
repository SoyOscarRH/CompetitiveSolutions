class Solution {
 public:
  auto isValidSequence(TreeNode* const root, const vector<int>& data, int index = 0) -> bool {
    if (not root) return false;
    if (index >= data.size() or data[index] != root->val) return false;

    if (!root->left and !root->right) return index == data.size() - 1;

    return isValidSequence(root->left, data, index + 1) or isValidSequence(root->right, data, index + 1);
  }
};