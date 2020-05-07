struct Solution {
  using node = TreeNode;
  auto findNode(node* root, int id, node* parent = nullptr, int depth = 0) -> pair<int, node*> {
    if (not root) return {-id, nullptr};
    if (root->val == id) return {depth, parent};

    const auto option1 = findNode(root->left, id, root, depth + 1);
    if (option1.first != -id) return option1;

    const auto option2 = findNode(root->right, id, root, depth + 1);
    if (option2.first != -id) return option2;

    return {-id, nullptr};
  }

  auto isCousins(node* const root, const int x, const int y) -> bool {
    if (not root) return false;

    const auto [depth_of_x, parent_of_x] = findNode(root, x);
    const auto [depth_of_y, parent_of_y] = findNode(root, y);

    return depth_of_x == depth_of_y and parent_of_x != parent_of_y;
  }
};
