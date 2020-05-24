class Solution {
 private:
  TreeNode* bstFromPreorder(vector<int>& preorder, int start, int end) {
    if (start > end) return nullptr;

    auto* node = new TreeNode {preorder[start]};

    auto i = 0;
    for (i = start; i <= end and preorder[i] <= node->val; ++i);

    node->left = bstFromPreorder(preorder, start + 1, i - 1);
    node->right = bstFromPreorder(preorder, i, end);

    return node;
  }

 public:
  auto bstFromPreorder(vector<int>& preorder) -> TreeNode* {
    return bstFromPreorder(preorder, 0, preorder.size() - 1);
  }
};