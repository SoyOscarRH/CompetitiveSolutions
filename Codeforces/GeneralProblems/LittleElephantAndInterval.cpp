#include <iostream>
using namespace std;

auto special_nums_until(const int64_t number) -> int64_t {
  if (number < 10) return number;

  const auto string_representation = to_string(number);
  const auto first_digit = string_representation.front();
  const auto last_digit = string_representation.back();

  auto special_nums = (number / 10) + 9;
  return (first_digit > last_digit) ? special_nums - 1 : special_nums;
}

auto main() -> int {
  int64_t a, b;
  cin >> a >> b;

  cout << special_nums_until(b) - special_nums_until(a - 1);
}
