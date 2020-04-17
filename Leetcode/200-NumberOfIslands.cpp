class Solution {
  struct point { int x, y; };
  static constexpr array<point, 4> moves {{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};

 public:
  inline auto is_ok(int x, int y, int n, int m) -> bool {
    return (0 <= x and x < n) and (0 <= y and y < m);
  }

  inline auto fillIsland(vector<vector<char>>& grid, const point& p) -> void {
    auto to_visit = stack<point> {{p}};
    const auto n = grid.size(), m = grid[0].size();
    while (not to_visit.empty()) {
      const auto [x, y] = to_visit.top();
      to_visit.pop();
      for (const auto delta : moves) {
        const auto dx = x + delta.x, dy = y + delta.y;
        if (is_ok(dx, dy, n, m) and grid[dx][dy] == '1') {
          grid[dx][dy] = '0';
          to_visit.push({dx, dy});
        }
      }
    }
  }

  auto numIslands(vector<vector<char>> grid) -> int {
    if (not grid.size()) return 0;
    const auto n = grid.size(), m = grid[0].size();
    auto result = 0;

    for (auto i = 0; i < n; ++i) {
      for (auto j = 0; j < m; ++j) {
        if (grid[i][j] == '0') continue;
        fillIsland(grid, {i, j});
        ++result;
      }
    }

    return result;
  }
};