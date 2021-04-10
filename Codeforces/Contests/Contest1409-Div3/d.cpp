#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using num = int64_t;

constexpr auto endline = '\n';

auto solve(const num n, const num s) {
  auto digits = to_string(n);

  const auto sum_of_all = [&]() {
    const auto offset = digits.size() * num('0');
    return accumulate(begin(digits), end(digits), num {0}) - offset;
  };

  while (sum_of_all() > s) {
    auto current = digits.find_last_not_of('0');
    auto const magic_digit = to_string(10 - (digits[current] - '0'));
    auto const to_add = magic_digit + string(digits.size() - 1 - current, '0');
    digits = to_string(stoll(digits) + stoll(to_add));
  }

  return stoll(digits) - n;
}

auto main() -> int {
  ios::sync_with_stdio(false);

  num tests;
  cin >> tests;

  while (tests--) {
    num n, s;
    cin >> n >> s;
    cout << solve(n, s) << endline;
  }

  return 0;
}