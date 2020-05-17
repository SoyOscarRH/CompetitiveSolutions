#include <iostream>
#include <vector>

using namespace std;
constexpr auto endline = '\n';

auto solve(const int numcase) -> void {
  cout << "Case #" << numcase << ": ";

  int n, k;
  cin >> n >> k;

  auto numbers = vector<int>(n);
  for (auto& num : numbers) cin >> num;

  auto count = 0, current = 0, i = 0;
  while (i < n) {
    current = numbers[i++];
    if (current != k) continue;

    for (auto expected = k - 1; expected >= 1 and i < n; --expected) {
      current = numbers[i++];
      if (current == k) expected = k;
      else if (current != expected) current = -1, expected = -1;
    }

    if (current == 1) ++count;
  }

  cout << count << endline;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tests;
  cin >> tests;
  for (auto test = 1; test <= tests; ++test) solve(test);

  return 0;
}