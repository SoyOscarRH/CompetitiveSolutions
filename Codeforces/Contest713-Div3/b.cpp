#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr auto endline = '\n';

auto solve() -> void {
  int n;
  cin >> n;

  auto lines = vector<string>(n);
  for (auto& line : lines) { cin >> line; }

  auto indexes = vector<pair<int, int>> {};
  for (size_t i = 0; i < lines.size(); ++i) {
    for (size_t j = 0; j < lines[i].size(); ++j) {
      if (lines[i][j] == '*') { indexes.emplace_back(i, j); }
    }
  }

  const auto [x1, y1] = indexes[0];
  const auto [x2, y2] = indexes[1];

  if (x1 != x2 and y1 != y2) {
    lines[x1][y2] = '*';
    lines[x2][y1] = '*';
  } else if (x1 != x2) {
    const auto new_y = (y1 + 1) % n;
    lines[x1][new_y] = '*';
    lines[x2][new_y] = '*';
  } else if (y1 != y2) {
    const auto new_x = (x1 + 1) % n;
    lines[new_x][y1] = '*';
    lines[new_x][y2] = '*';
  } else {
    const auto new_x = (x1 + 1) % n;
    const auto new_y = (y1 + 1) % n;
    lines[new_x][new_y] == '*';
    lines[x1][new_y] = '*';
    lines[new_x][y1] = '*';
  }

  for (const auto& line : lines) { cout << line << '\n'; }
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests;
  cin >> tests;

  while (tests--) { solve(); }

  return 0;
}