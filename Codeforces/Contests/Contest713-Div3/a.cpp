#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using num = int64_t;

constexpr auto endline = '\n';

auto solve() -> num {
  int n;
  cin >> n;

  auto nums = vector<int>(n);
  for (auto& x : nums) { cin >> x; }

  auto indexes = map<int, set<int>> {};
  for (auto i = 0; i < n; ++i) { indexes[nums[i]].insert(i); }

  for (const auto& item : indexes) {
    if (item.second.size() == 1) { return *item.second.begin() + 1; }
  }

  return -1;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  num tests;
  cin >> tests;

  while (tests--) { cout << solve() << endline; }

  return 0;
}