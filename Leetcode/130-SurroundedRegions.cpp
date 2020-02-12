class Solution {
 public:
  using matrix = vector<vector<char>>;
  int m, n;
  const char mark = 'Y';

  vector<pair<int, int>> moves = {
      {1, 0},   // left
      {-1, 0},  // right
      {0, 1},   // up
      {0, -1},  // down
  };

  auto mark_adjacent(matrix& grid, const int i, const int j) -> void {
    auto to_check = queue<pair<int, int>> {{{i, j}}};

    grid[i][j] = mark;

    while (not to_check.empty()) {
      const auto [xi, yi] = to_check.front();
      to_check.pop();

      for (auto [x, y] : moves) {
        x += xi;
        y += yi;
        if (x < 0 or x >= m) continue;
        if (y < 0 or y >= n) continue;
        if (grid[x][y] == 'X') continue;
        if (grid[x][y] == mark) continue;

        grid[x][y] = mark;
        to_check.push({x, y});
      }
    }
  }

  void solve(matrix& grid) {
    m = grid.size(), n = m ? grid[0].size() : 0;
    if (not n) return;

    for (int i = 0; i < m; i++) {
      if (grid[i][0] == 'O') mark_adjacent(grid, i, 0);
      if (grid[i][n - 1] == 'O') mark_adjacent(grid, i, n - 1);
    }

    for (int i = 0; i < n; i++) {
      if (grid[0][i] == 'O') mark_adjacent(grid, 0, i);
      if (grid[m - 1][i] == 'O') mark_adjacent(grid, m - 1, i);
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        grid[i][j] = grid[i][j] == mark ? 'O' : 'X';
      }
    }
  }
};