#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;
using num = int64_t;

constexpr auto endline = '\n';

auto solve(const num a, const num b) -> num {
  const auto [min_val, max_val] = minmax(a, b);

  return ceil((max_val - min_val) / 10.0);
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  num tests;
  cin >> tests;

  while (tests--) {
    num a, b;
    cin >> a >> b;
    cout << solve(a, b) << endline;
  }

  return 0;
}