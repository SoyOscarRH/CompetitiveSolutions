#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using num = int_fast64_t;

auto solve() -> string {
  num n, swaps;
  cin >> n >> swaps;

  auto nums = vector<int>(n);
  for (auto& x : nums) cin >> x;

  num min_swaps = 0;
  for (int i = 0; i < n; ++i) {
    const auto correct_num_here = i + 1;
    if (nums[i] == correct_num_here) continue;

    while (nums[i] != correct_num_here) {
      auto temporal = nums[nums[i] - 1];
      nums[nums[i] - 1] = nums[i];
      nums[i] = temporal;
      ++min_swaps;
    }
  }

  swaps -= min_swaps;
  if (swaps < 0) return "No";
  if (swaps % 2 == 0) return "Yes";
  return "No";
}

auto main() -> int {
  ios::sync_with_stdio(false);
  num test_case;
  cin >> test_case;
  for (auto test = 0; test < test_case; ++test) { cout << solve() << '\n'; }

  return 0;
}