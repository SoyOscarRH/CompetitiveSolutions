#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

constexpr auto endline = '\n';

auto solve() -> void {
  int64_t n;
  cin >> n;

  const auto m = n + 2;
  auto nums = vector<int64_t>(m);
  for (auto& num : nums) { cin >> num; }

  auto total_sum = accumulate(cbegin(nums), cend(nums), int64_t {});
  sort(begin(nums), end(nums));

  const auto max = m - 1, almost_max = m - 2;
  for (auto i = 0; i < m; ++i) {
    const auto the_biggest_index = i == max ? almost_max : max;
    const auto the_biggest = nums[the_biggest_index];
    const auto random = nums[i];

    const auto option_sum = total_sum - random - the_biggest;
    if (the_biggest == option_sum) {
      for (auto j = 0; j < m; ++j) {
        if (j == i or j == the_biggest_index) { continue; }
        cout << nums[j] << " ";
      }
      cout << endl;
      return;
    }
  }

  cout << "-1" << endline;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  int tests;
  cin >> tests;

  while (tests--) { solve(); }
  return 0;
}