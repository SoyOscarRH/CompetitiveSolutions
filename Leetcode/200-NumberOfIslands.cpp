class Solution {
 public:
  using matrix = vector<vector<char>>;

  int m, n;

  vector<pair<int, int>> moves = {
      {1, 0},   // left
      {-1, 0},  // right
      {0, 1},   // up
      {0, -1},  // down
  };

  auto remove_adjacent(matrix& grid, const int i, const int j) -> void {
    auto to_check = queue<pair<int, int>> {{{i, j}}};

    while (not to_check.empty()) {
      auto current = to_check.front();
      to_check.pop();

      for (const auto [xi, yi] : moves) {
        auto [x, y] = current;

        x += xi;
        y += yi;
        if (x < 0 or x >= m) continue;
        if (y < 0 or y >= n) continue;
        if (grid[x][y] != '1') continue;

        grid[x][y] = '0';
        to_check.push({x, y});
      }
    }
  }

  int numIslands(matrix& grid) {
    m = grid.size(), n = m ? grid[0].size() : 0;
    if (not n) return 0;

    auto islands = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1') {
          grid[i][j] = '0';
          islands++;
          remove_adjacent(grid, i, j);
        }
      }
    }

    return islands;
  }
};