#include <array>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

constexpr auto endline = '\n';
using num = int_fast32_t;

constexpr auto max_possible_square = 3165;
array<num, max_possible_square> possibles;

auto count_subarray_sum(const vector<num>& numbers) {
  num count = 0;
  auto m = unordered_map<num, num> {};
  m[0] = 1;

  num sum = 0;
  for (const auto& v : numbers) {
    sum += v;

    for (auto k : possibles) {
      if (sum - k < 0) break;
      if (m.count(sum - k)) count += m[sum - k];
    }

    ++m[sum];
  }

  return count;
}

auto solve(const num numcase) -> void {
  cout << "Case #" << numcase << ": ";

  num n;
  cin >> n;

  auto numbers = vector<num>(n);
  for (auto& number : numbers) cin >> number;

  cout << count_subarray_sum(numbers) << endline;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (auto i = num {}; i < max_possible_square; ++i) possibles[i] = i * i;

  num tests;
  cin >> tests;
  for (auto test = num {1}; test <= tests; ++test) solve(test);

  return 0;
}