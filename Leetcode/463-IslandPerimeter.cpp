struct Solution {
  auto islandPerimeter(const vector<vector<int>>& grid) -> int {
    const auto row = static_cast<int>(grid.size());
    const auto col = static_cast<int>(grid[0].size());
    auto result = 0;

    const auto block_at = [row, col, &grid](const int x, const int y) -> int {
      if (x < 0 or x >= row) return 0;
      if (y < 0 or y >= col) return 0;
      return grid[x][y] == 1;
    };

    for (auto i = 0; i < row; ++i) {
      for (auto j = 0; j < col; ++j) {
        if (grid[i][j] == 0) continue;
        const auto neighbors =
            block_at(i + 1, j) + block_at(i, j + 1) + block_at(i - 1, j) + block_at(i, j - 1);
        result += 4 - neighbors;
      }
    }

    return result;
  }
};