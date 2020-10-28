#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

auto solve() -> string {
  int money_of_a, money_of_b, money_of_c, money_to_give;
  cin >> money_of_a >> money_of_b >> money_of_c >> money_to_give;

  const auto money_of_sister_with_more = max({money_of_a, money_of_b, money_of_c});

  const auto money_to_give_to_tie = (money_of_sister_with_more - money_of_a) +
                                    (money_of_sister_with_more - money_of_b) +
                                    (money_of_sister_with_more - money_of_c);

  const auto money_left_to_give = money_to_give - money_to_give_to_tie;

  if (money_left_to_give < 0) return "NO";

  return money_left_to_give % 3 == 0 ? "YES" : "NO";
}

auto main() -> int {
  int tests;
  cin >> tests;
  for (auto test = 0; test < tests; ++test) { cout << solve() << endl; }

  return 0;
}