struct Solution {
  auto checkStraightLine(const vector<vector<int>>& coordinates) -> bool {
    if (coordinates.size() < 3) return true;

    const auto x0 = coordinates[0][0], y0 = coordinates[0][1];
    const auto x1 = coordinates[1][0], y1 = coordinates[1][1];
    const auto dx = x1 - x0, dy = y1 - y0;

    for (const auto& coordinate : coordinates) {
      const auto x = coordinate[0], y = coordinate[1];
      if (dx * (y - y1) != dy * (x - x1)) return false;
    }
    return true;
  }
};