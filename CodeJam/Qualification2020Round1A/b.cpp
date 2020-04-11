#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
constexpr auto endline = '\n';

auto solve(const int numcase) -> void {
  int n = 0ull;
  cin >> n;

  if (n < 4) {
    auto r = 1ull, k = 1ull;
    for (int i = 0; i < n; ++i) {
      cout << r << " " << k << endline;
      ++r, ++k;
    }
  } else {
    cout << "1 1" << endline;
    cout << "2 1" << endline;
    cout << "3 2" << endline;
    auto total = 4ull;
    auto next = 3ull;
    auto r = 3ull, k = 2ull;

    while (total + next <= n) {
      ++r, ++k;
      cout << r << " " << k << endline;
      total += next;
      ++next;
    }

    if (total != n) ++k;
    while (total != n) {
      ++total;
      cout << r << " " << k << endline;
      ++r, ++k;
    }
  }
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  auto tests = 10;
  cin >> tests;

  for (auto i = 1; i <= tests; ++i) {
    cout << "Case #" << i << ":" << endline;
    solve(i);
  }

  return 0;
}