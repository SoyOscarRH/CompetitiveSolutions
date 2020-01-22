#include <algorithm>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using num = int64_t;

auto solve() {
  num a, b, c, n;
  cin >> a >> b >> c >> n;

  const auto max_num = max({a, b, c});
  const auto to_give_to_that = (max_num - a) + (max_num - b) + (max_num - c);
  const auto left = n - to_give_to_that;

  cout << (left >= 0 and left % 3 == 0 ? "YES" : "NO") << endl;
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