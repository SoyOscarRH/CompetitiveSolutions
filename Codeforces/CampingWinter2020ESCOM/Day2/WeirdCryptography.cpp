#include <algorithm>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
constexpr auto endline = '\n';

auto solve(int n) -> string {
  auto words_seen = unordered_map<string, int> {};
  auto buffer = string {};
  for (auto i = 0; i < n; i++) {
    cin >> buffer;
    ++words_seen[buffer];
  }

  auto groups = vector<int> {};
  for (const auto& [_, times_seen] : words_seen) groups.push_back(times_seen);

  sort(begin(groups), end(groups), greater<int> {});

  auto const num_digits = groups[0];
  auto result = string(num_digits, '0');

  for (auto group : groups) {
    for (auto i = 0; i < group; i++) ++result[i];
  }

  reverse(begin(result), end(result));

  return result;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto n = 0;
  cin >> n;

  for (auto i = 1; n; i++) {
    cout << "Case " << i << ": " << solve(n) << endline;
    cin >> n;
  }

  return 0;
}