class Solution {
  using matrix = vector<vector<int>>;

 public:
  int minPathSum(const matrix& grid) {
    const auto n = grid.size(), m = grid[0].size();
    auto min_sum_to = matrix(n, vector<int>(m, -1));

    for (auto i = 0; i < n; ++i) {
      for (auto j = 0; j < m; ++j) {
        const auto option_a = i == 0 ? INT_MAX : min_sum_to[i - 1][j];
        const auto option_b = j == 0 ? INT_MAX : min_sum_to[i][j - 1];
        const auto better = min(option_a, option_b);

        min_sum_to[i][j] = (better == INT_MAX ? 0 : better) + grid[i][j];
      }
    }

    return min_sum_to.back().back();
  }
};