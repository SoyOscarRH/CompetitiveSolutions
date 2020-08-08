struct Solution {
  auto verticalTraversal(TreeNode* const root) -> vector<vector<int>> {
    auto positions = map<int, vector<pair<int, int>>> {};
    auto to_visit = queue<tuple<TreeNode*, int, int>> {{{root, 0, 0}}};
    while (not to_visit.empty()) {
      auto [current, i, level] = to_visit.front();
      to_visit.pop();
      positions[i].emplace_back(level, current->val);
      if (current->left) to_visit.emplace(current->left, i - 1, level + 1);
      if (current->right) to_visit.emplace(current->right, i + 1, level + 1);
    }

    auto result = vector<vector<int>> {};
    for (auto& [_, data] : positions) {
      auto temporal = vector<int>(data.size());
      sort(begin(data), end(data));
      for (auto i = 0; i < data.size(); ++i) { temporal[i] = data[i].second; }

      result.emplace_back(std::move(temporal));
    }

    return result;
  }
};