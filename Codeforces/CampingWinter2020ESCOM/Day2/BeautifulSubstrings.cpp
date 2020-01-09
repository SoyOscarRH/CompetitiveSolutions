#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>

using namespace std;
using num = int64_t;
constexpr auto endline = '\n';

auto solve() -> num {
  array<array<bool, 26>, 26> to_find {};
  array<bool, 26> ended {};

  auto n = 0, m = 0, k = 0;
  cin >> n >> m >> k;

  auto a = string {}, b = string {};
  a.reserve(n), b.reserve(m);
  cin >> a >> b;

  for (auto i = 0, step = k - 1; i + step < a.size(); ++i) {
    const auto x = a[i] - 'a', y = a[i + step] - 'a';
    ended[y] = to_find[x][y] = true;
  }

  auto result = num {};
  array<num, 26> bag_of_seen {};

  for (auto letter : b) {
    const auto y = letter - 'a';
    ++bag_of_seen[y];

    if (not ended[y]) continue;

    for (auto x = 0; x < 26; x++)
      if (bag_of_seen[x] and to_find[x][y]) result += bag_of_seen[x];
  }

  return result;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto tests = 0;
  cin >> tests;

  while (tests--) cout << solve() << endline;

  return 0;
}