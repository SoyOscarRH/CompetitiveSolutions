#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
constexpr auto endline = '\n';

auto reverse_sort_cost(vector<int>& nums) {
  auto cost = 0;

  for (auto i = begin(nums); (i + 1) != end(nums); ++i) {
    const auto j = min_element(i, end(nums));
    reverse(i, j + 1);
    const auto iteration = distance(i, j) + 1;
    cost += iteration;
  }

  return cost;
}

auto solve(const int test_case) -> void {
  int num_elements;
  cin >> num_elements;

  auto nums = vector<int>(num_elements);
  for (auto& num : nums) { cin >> num; }

  cout << "Case #" << test_case << ": " << reverse_sort_cost(nums) << endline;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tests;
  cin >> tests;
  for (auto test = 1; test <= tests; ++test) { solve(test); }

  return 0;
}