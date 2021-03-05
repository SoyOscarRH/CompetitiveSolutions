#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

constexpr auto endline = '\n';

auto solve(const string& password, const set<char>& special_chars) -> string {
  auto one_lower_case = false;
  auto one_upper_case = false;

  auto one_digit_case = false;
  auto consecutive_case = false;

  auto one_special_case = false;
  auto at_least_10 = password.size() >= 10;

  auto prev = 'a';
  for (auto letter : password) {
    if (islower(letter)) one_lower_case = true;
    if (isupper(letter)) one_upper_case = true;

    if (isdigit(letter)) one_digit_case = true;
    if (isdigit(prev) and isdigit(letter)) {
      const int d1 = prev - '0';
      const int d2 = letter - '0';

      if (abs(d2 - d1) == 1) consecutive_case = true;
    }

    if (not one_special_case and special_chars.count(letter) != 0) one_special_case = true;

    prev = letter;
  }

  auto rules_checked = 0;
  if (one_lower_case) ++rules_checked;
  if (one_upper_case) ++rules_checked;
  if (one_digit_case and (not consecutive_case)) ++rules_checked;
  if (one_special_case) ++rules_checked;
  if (at_least_10) ++rules_checked;

  if (rules_checked == 5) { return "Strong"; }
  if (rules_checked == 4) { return "Good"; }
  if (rules_checked == 3) { return "Weak"; }

  return "Rejected";
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tests;
  cin >> tests;

  auto special_chars = set<char> {'.', '#', '$', '%', '/', '(', '&', ')'};
  for (auto test = 0; test < tests; ++test) {
    string password;
    cin >> password;
    cout << "Assertion number #" << test + 1 << ": " << solve(password, special_chars) << endline;
  }

  return 0;
}