#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

constexpr auto endline = '\n';

auto solve(const vector<int>& nums) -> int {
  auto sorted_nums = nums;
  sort(begin(sorted_nums), end(sorted_nums));

  auto sorted_index_for = unordered_map<int, int> {};
  auto i = 0;
  for (const auto num : sorted_nums) { sorted_index_for[num] = i++; }

  auto max_distance = 0;

  i = 0;
  for (const auto num : nums) {
    max_distance = max(max_distance, abs(sorted_index_for[num] - i++));
  }

  return max_distance;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int num_boxes;
  cin >> num_boxes;

  auto nums = vector<int>(num_boxes);
  for (auto& box : nums) cin >> box;

  cout << solve(nums) << endline;

  return 0;
}