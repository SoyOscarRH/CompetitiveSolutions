class Solution {
  enum class element { empty = 0, fresh_orange = 1, rooten_orange = 2 };
  static constexpr array<pair<int, int>, 4> moves = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};

 public:
  auto orangesRotting(vector<vector<int>>& grid) -> int {
    const auto n = grid.size(), m = grid[0].size();

    auto rooten_to_check = vector<pair<int, int>> {};
    auto num_fresh_oranges = 0;
    for (auto i = 0; i < n; ++i) {
      for (auto j = 0; j < m; ++j) {
        const auto current = static_cast<element>(grid[i][j]);
        if (current == element::rooten_orange) { rooten_to_check.emplace_back(i, j); }
        if (current == element::fresh_orange) { ++num_fresh_oranges; }
      }
    }

    if (num_fresh_oranges == 0) return 0;

    auto num_days = 0;
    while (not rooten_to_check.empty()) {
      auto rooten_to_check_next_day = vector<pair<int, int>> {};

      for (const auto [i, j] : rooten_to_check) {
        for (const auto [move_in_i, move_in_j] : moves) {
          const auto di = i + move_in_i, dj = j + move_in_j;
          if (di < 0 or di >= n or dj < 0 or dj >= m) continue;
          if (static_cast<element>(grid[di][dj]) == element::fresh_orange) {
            grid[di][dj] = static_cast<int>(element::rooten_orange);
            rooten_to_check_next_day.emplace_back(di, dj);
            num_fresh_oranges--;
          }
        }
      }

      rooten_to_check = move(rooten_to_check_next_day);
      ++num_days;
    }

    return num_fresh_oranges == 0 ? num_days - 1 : -1;
  }
};