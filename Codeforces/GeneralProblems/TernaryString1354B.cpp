#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

using num = int;

const auto big_and_invalid_num = numeric_limits<num>::max();
auto size_of_min_substring_with_123(const string& input) -> num {
  int last_time_i_saw_1 = 0, last_time_i_saw_2 = 0, last_time_i_saw_3 = 0;
  auto size_of_min_valid_substring = big_and_invalid_num;

  for (num i = 0; i < input.size(); ++i) {
    if (input[i] == '1') last_time_i_saw_1 = i + 1;
    if (input[i] == '2') last_time_i_saw_2 = i + 1;
    if (input[i] == '3') last_time_i_saw_3 = i + 1;

    if (last_time_i_saw_1 and last_time_i_saw_2 and last_time_i_saw_3) {
      const auto [begin_of_substr, end_of_substr] =
          minmax({last_time_i_saw_1, last_time_i_saw_2, last_time_i_saw_3});
      
      const auto candidate_substring_size = end_of_substr - begin_of_substr + 1;
      size_of_min_valid_substring = min(size_of_min_valid_substring, candidate_substring_size);
    }
  }

  if (size_of_min_valid_substring == big_and_invalid_num) { return 0; }

  return size_of_min_valid_substring;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  auto tests = 0;
  cin >> tests;
  auto buffer = string {};

  for (auto test = 0; test < tests; ++test) {
    cin >> buffer;
    cout << size_of_min_substring_with_123(buffer) << "\n";
  }

  return 0;
}
