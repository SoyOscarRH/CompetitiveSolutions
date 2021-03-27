#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
constexpr auto endline = '\n';

auto solve(const int test_case) -> void {
  int num_elements, value;
  cin >> num_elements >> value;

  const auto min_value = num_elements - 1;
  const auto max_value = ((num_elements * (num_elements + 1)) / 2) - 1;

  if (value < min_value or value > max_value) {
    cout << "Case #" << test_case << ": "
         << "IMPOSSIBLE" << endline;

    return;
  }

  auto sums = vector<int>(num_elements - 1, 1);
  auto current = 0, total = num_elements - 1, limit = num_elements;
  while (total != value) {
    if (sums[current] < limit) {
      sums[current] += 1;
      total += 1;
    } else {
      current += 1;
      limit -= 1;
    }
  }

  auto translater = map<int, int> {};
  auto nums = vector<int> {};
  for (auto i = 0; i < num_elements; ++i) { nums.push_back(i + 1); }

  for (auto i = 0; i < sums.size(); ++i) {
    const auto element_shift = sums[i];
    const auto element_value = i + 1;

    const auto here = begin(nums) + i;
    reverse(here, here + element_shift);
    translater[nums[i]] = element_value;
  }

  translater[nums.back()] = num_elements;

  cout << "Case #" << test_case << ": ";
  for (auto i = 0; i < num_elements; ++i) { cout << translater[i + 1] << " "; }
  cout << endl;
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