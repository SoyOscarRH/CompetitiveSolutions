#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using point = pair<int, int>;
const auto endline = '\n';

auto solve() {
  auto num_boxes = 0;
  cin >> num_boxes;

  auto packages = vector<point>(num_boxes);
  for (auto& p : packages) cin >> p.first >> p.second;
  sort(begin(packages), end(packages));

  auto result = string {};
  auto current = point {0, 0};
  for (const auto next : packages) {
    auto [xf, yf] = next;
    auto [xi, yi] = current;
    const auto right = xf - xi;
    const auto up = yf - yi;

    if (right < 0 or up < 0) {
      cout << "NO" << endline;
      return;
    }

    result.append(right, 'R');
    result.append(up, 'U');

    current = next;
  }

  cout << "YES" << endline << result << endline;
}

auto main() -> int {
  ios::sync_with_stdio(false);

  auto tests = 0;
  cin >> tests;

  while (tests--) {
    solve();
  }

  return 0;
}