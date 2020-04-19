#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
constexpr auto endline = '\n';

auto solve(const int numcase) -> void {
  cout << "Case #" << numcase << ": ";

  int n_buses = 0;
  cin >> n_buses;

  auto points = vector<int>(n_buses);
  for (auto& point : points) cin >> point;

  auto count = 0;
  for (auto i = 1; i < n_buses - 1; ++i) {
    if (points[i] > points[i - 1] and 
        points[i] > points[i + 1]) ++count;
  }

  cout << count << endline;
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