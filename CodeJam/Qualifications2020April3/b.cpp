#include <iostream>
#include <string>
#include <vector>

using namespace std;
constexpr auto endline = '\n';

auto solve(const int testcase) -> void {
  auto digits = string {};
  cin >> digits;

  digits += '0';

  auto result = string {};
  result.reserve(digits.size());

  auto level = 0;

  for (const auto digit_char : digits) {
    const auto digit = digit_char - '0';

    for (; level < digit; ++level) result += '(';
    for (; level > digit; --level) result += ')';
    result += digit_char;
  }
  result.pop_back();
  cout << "Case #" << testcase << ": " << result << endline;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto tests = 10;
  cin >> tests;

  for (auto i = 1; i <= tests; i++) solve(i);

  return 0;
}