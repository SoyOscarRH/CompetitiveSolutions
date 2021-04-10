#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using num = int64_t;

constexpr auto endline = '\n';

auto solve(const num a, const num b, const num x, const num y, const num n) -> num {
  const auto new_a = max(a - n, x);
  const auto remaining_ops = n - (a - new_a);
  const auto new_b = max(b - remaining_ops, y);

  return new_a * new_b;
}

auto main() -> int {
  ios::sync_with_stdio(false);

  num tests;
  cin >> tests;

  while (tests--) {
    num a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    cout << min(solve(a, b, x, y, n), solve(b, a, y, x, n)) << endline;
  }

  return 0;
}