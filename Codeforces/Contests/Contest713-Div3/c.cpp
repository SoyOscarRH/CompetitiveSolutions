#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr auto endline = '\n';

auto is_odd(const int x) { return x % 2 == 1; }
auto solve() -> string {
  int final_num_of_0, final_num_of_1;
  cin >> final_num_of_0 >> final_num_of_1;

  string data;
  cin >> data;

  if (is_odd(final_num_of_0) and is_odd(final_num_of_1)) { return "-1"; }

  auto missings = vector<pair<int, int>> {};
  const auto n = final_num_of_0 + final_num_of_1;

  for (auto i = 0, j = n - 1; i <= j; ++i, --j) {
    if (data[i] != '?' and data[j] != '?') {
      if (data[i] != data[j]) { return "-1"; }
    } else if (data[i] != '?') {
      data[j] = data[i];
    } else if (data[j] != '?') {
      data[i] = data[j];
    } else {
      missings.emplace_back(i, j);
    }
  }

  const auto num_of_0 = static_cast<int>(count(cbegin(data), cend(data), '0'));
  const auto num_of_1 = static_cast<int>(count(cbegin(data), cend(data), '1'));
  const auto num_of_x = static_cast<int>(count(cbegin(data), cend(data), '?'));

  auto num_of_0_to_put = final_num_of_0 - num_of_0;
  auto num_of_1_to_put = final_num_of_1 - num_of_1;

  if (num_of_x != (num_of_0_to_put + num_of_1_to_put)) { return "-1"; }
  if (num_of_0_to_put < 0 or num_of_1_to_put < 0) { return "-1"; }

  for (const auto [i, j] : missings) {
    const auto to_modify = (i != j) ? 2 : 1;
    if (num_of_0_to_put >= to_modify) {
      data[i] = data[j] = '0';
      num_of_0_to_put -= to_modify;
    } else if (num_of_1_to_put >= to_modify) {
      data[i] = data[j] = '1';
      num_of_1_to_put -= to_modify;
    } else {
      return "-1";
    }
  }

  return (num_of_0_to_put == 0 and num_of_1_to_put == 0) ? data : "-1";
}

auto main() -> int {
  ios::sync_with_stdio(false);
  int tests;
  cin >> tests;

  while (tests--) { cout << solve() << endline; }
  return 0;
}