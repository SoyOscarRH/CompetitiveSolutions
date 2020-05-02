#include <algorithm>
#include <iostream>

#include <map>
#include <string>
#include <vector>

using namespace std;
constexpr auto endline = '\n';

using num = long long;

auto solve(const int numcase) -> void {
  cout << "Case #" << numcase << ": ";

  auto moves = string {};
  auto target_x = 0ll, target_y = 0ll;
  cin >> target_x >> target_y >> moves;
  moves += "_";

  auto steps = 0ll;
  for (const auto move : moves) {
    auto distance = abs(target_x) + abs(target_y);

    if (distance <= steps) {
      cout << steps << endline;
      return;
    }

    if (move == 'E') ++target_x;
    if (move == 'W') --target_x;
    if (move == 'N') ++target_y;
    if (move == 'S') --target_y;

    ++steps;
  }

  cout << "IMPOSSIBLE" << endline;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  auto tests = 10;
  cin >> tests;

  for (auto test = 1; test <= tests; ++test) solve(test);

  return 0;
}