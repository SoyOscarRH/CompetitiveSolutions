#include <array>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

using num = int;

auto size_of_min_substring_with_123(const string& input) -> num {
  int one = 0, two = 0, three = 0;
  const auto invalid = numeric_limits<num>::max();
  auto size_of_min = invalid;

  for (num i = 0; i < input.size(); ++i) {
    if (input[i] == '1') one = i + 1;
    if (input[i] == '2') two = i + 1;
    if (input[i] == '3') three = i + 1;

    if (one and two and three) {
      const auto [y, x] = minmax(one, two);
      const auto current_size = max(x, three) - min(y, three) + 1;

      size_of_min = min(size_of_min, current_size);
    }
  }

  if (size_of_min == invalid) { return 0; }

  return size_of_min;
}

auto main() -> int {
  auto tests = 0;
  cin >> tests;
  auto buffer = string {};

  for (auto test = 0; test < tests; ++test) {
    cin >> buffer;
    cout << size_of_min_substring_with_123(buffer) << "\n";
  }

  return 0;
}
