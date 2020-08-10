class Solution {
  enum class orange { empty = 0, fresh = 1, rooten = 2 };
  vector<pair<int, int>> moves {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

 public:
  auto orangesRotting(vector<vector<int>>& grid) -> int {
    const int x = grid.size(), y = grid[0].size();

    auto rooten_to_check = queue<pair<int, int>> {};
    auto num_oranges = 0;
    for (auto i = 0; i < x; ++i) {
      for (auto j = 0; j < y; ++j) {
        if (static_cast<orange>(grid[i][j]) == orange::rooten) { rooten_to_check.emplace(i, j); }
        if (static_cast<orange>(grid[i][j]) != orange::empty) { ++num_oranges; }
      }
    }

    auto days = 0;
    while (not rooten_to_check.empty()) {
      auto num_to_check = rooten_to_check.size();
      for (auto k = 0; k < num_to_check; ++k) {
        auto [i, j] = rooten_to_check.front();
        rooten_to_check.pop();
        num_oranges--;

        for (const auto [di, dj] : moves) {
          const auto i2 = i + di, j2 = j + dj;
          if (i2 < 0 or i2 >= x or j2 < 0 or j2 >= y) continue;
          auto& current = grid[i2][j2];
          if (static_cast<orange>(current) == orange::fresh) {
            current = static_cast<int>(orange::rooten);
            rooten_to_check.emplace(i2, j2);
          }
        }
      }
      ++days;
    }

    return (num_oranges == 0)? max(0, days - 1) : -1;
  }
};