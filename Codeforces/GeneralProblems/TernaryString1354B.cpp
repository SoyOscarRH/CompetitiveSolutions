#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <optional>
#include <string>

using namespace std;

template <typename num>
auto size_of_min_substring_with_123(const string& input) -> num {
  auto size_of_min_valid_substr = optional<num> {};
  auto last_index_of_1 = optional<num> {}, last_index_of_2 = optional<num> {},
       last_index_of_3 = optional<num> {};

  for (num i = 0; i < input.size(); ++i) {
    if (input[i] == '1') { last_index_of_1 = i; }
    if (input[i] == '2') { last_index_of_2 = i; }
    if (input[i] == '3') { last_index_of_3 = i; }

    if (last_index_of_1 and last_index_of_2 and last_index_of_3) {
      const auto [first, last] = minmax({*last_index_of_1, *last_index_of_2, *last_index_of_3});
      const auto candidate_size = 1 + (last - first);

      if (not size_of_min_valid_substr) { size_of_min_valid_substr = candidate_size; }
      size_of_min_valid_substr = min(*size_of_min_valid_substr, candidate_size);
    }
  }

  return size_of_min_valid_substr.value_or(0);
}

auto main() -> int {
  ios::sync_with_stdio(false);
  auto tests = 0;
  cin >> tests;

  auto buffer = string {};
  for (auto test = 0; test < tests; ++test) {
    cin >> buffer;
    cout << size_of_min_substring_with_123<int>(buffer) << "\n";
  }

  return 0;
}
