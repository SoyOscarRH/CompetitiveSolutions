#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <optional>
#include <string>

using namespace std;

template <typename num>
auto size_of_min_substring_with_123(const string& input) -> num {
  auto size_of_min_valid_substring = optional<num>{};
  auto last_time_saw_1 = optional<num>{}, 
       last_time_saw_2 = optional<num>{},
       last_time_saw_3 = optional<num>{};

  for (num i = 0; i < input.size(); ++i) {
    if (input[i] == '1') last_time_saw_1 = i;
    if (input[i] == '2') last_time_saw_2 = i;
    if (input[i] == '3') last_time_saw_3 = i;

    if (last_time_saw_1 and last_time_saw_2 and last_time_saw_3) {
      const auto indexes = {*last_time_saw_1, *last_time_saw_2, *last_time_saw_3};
      const auto [begin_of_substr, end_of_substr] =  minmax(indexes);
      const auto candidate_size = 1 + (end_of_substr - begin_of_substr);
      if (!size_of_min_valid_substring or candidate_size < size_of_min_valid_substring) {
        size_of_min_valid_substring = candidate_size;
      }
    }
  }

  return size_of_min_valid_substring.value_or(0);
}

auto main() -> int {
  ios::sync_with_stdio(false);
  auto tests = 0;
  cin >> tests;

  auto buffer = string{};
  for (auto test = 0; test < tests; ++test) {
    cin >> buffer;
    cout << size_of_min_substring_with_123<int>(buffer) << "\n";
  }

  return 0;
}
