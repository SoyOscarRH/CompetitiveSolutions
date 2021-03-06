#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
constexpr auto endline = '\n';

using num = long long;

auto solve() -> void {
  num n, max_capacity;
  cin >> n >> max_capacity;

  auto weights = vector<num> (n);
  for (auto& w : weights) cin >> w;

  sort(begin(weights), end(weights));

  num i = 0, j = weights.size() - 1;
  auto required = weights.size();
  while (i < j) {
    if ((weights[i] + weights[j]) <= max_capacity) {
      --required;
      --j;
      ++i;
    }
    else --j;
  }

  cout << required << endline;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();

  return 0;
}