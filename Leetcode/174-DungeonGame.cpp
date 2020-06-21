struct Solution {
  auto calculateMinimumHP(const vector<vector<int>>& dungeon) -> int {
    const int m = dungeon.size(), n = dungeon[0].size();

    auto min_hp_at_pos = vector<vector<int>>(m + 1, vector<int>(n + 1, INT_MAX));
    min_hp_at_pos[m][n - 1] = 1;
    min_hp_at_pos[m - 1][n] = 1;

    for (auto i = m - 1; i >= 0; --i) {
      for (auto j = n - 1; j >= 0; --j) {
        const auto need = min(min_hp_at_pos[i + 1][j], min_hp_at_pos[i][j + 1]) - dungeon[i][j];
        min_hp_at_pos[i][j] = need <= 0 ? 1 : need;
      }
    }
    
    return min_hp_at_pos[0][0];
  }
};