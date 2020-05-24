#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
constexpr auto endline = '\n';

using num = long long;

auto solve() -> void {
  int n;
  cin >> n;
  auto fillers = vector<int>(n);
  for (auto& filler : fillers) cin >> filler;

  sort(begin(fillers), end(fillers));
  auto least = 1.0;
  for (auto ballon = 1; ballon <= n; ++ballon) {
    if (ballon < fillers[ballon - 1]) {
      cout << "IMPOSSIBLE" << endline;
      exit(0);
    }

    least = min(least, double(fillers[ballon - 1]) / ballon);
  }

  cout << least << endline;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
  return 0;
}