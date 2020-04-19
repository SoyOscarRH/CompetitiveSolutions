#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <cstdint>

using namespace std;
constexpr auto endline = '\n';

auto solve(const int numcase) -> void {
  cout << "Case #" << numcase << ": ";

  auto n_buses = 0ull, days = 0ull;
  cin >> n_buses >> days;

  auto buses = vector<uint64_t>(n_buses);
  for (auto& bus : buses) cin >> bus;
  reverse(begin(buses), end(buses));

  auto max_day = days;
  for (const auto bus : buses) {
    max_day -= max_day % bus;
  }

  cout << max_day << endline;
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