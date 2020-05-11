struct Solution {
  using grid = vector<vector<int>>;
  constexpr static array<pair<int, int>, 4> moves = {{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};

  auto floodFill(grid image, const int sr, const int sc, const int new_color)  -> grid {
    const auto n = image.size(), m = image[0].size();
    const auto original_color = image[sr][sc];

    auto to_visit = queue<pair<int, int>> {{{sr, sc}}};
    auto seen = set<pair<int, int>> {{{sr, sc}}};
    image[sr][sc] = new_color;

    while (not to_visit.empty()) {
      const auto [start_x, start_y] = to_visit.front();
      to_visit.pop();

      for (const auto [dx, dy] : moves) {
        const auto x = start_x + dx, y = start_y + dy;

        if ((0 > x or x >= n) or (0 > y or y >= m)) continue;
        if (seen.find({x, y}) != end(seen)) continue;
        if (image[x][y] != original_color) continue;
        image[x][y] = new_color;
        to_visit.push({x, y});
        seen.insert({x, y});
      }
    }

    return image;
  }
};