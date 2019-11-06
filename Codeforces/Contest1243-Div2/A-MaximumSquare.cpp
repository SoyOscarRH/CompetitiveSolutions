#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr auto endline = '\n';

auto solve() {
  auto number_of_titles = 10;
  cin >> number_of_titles;

  auto stuff = vector<int>(number_of_titles);
  for (auto& x : stuff) cin >> x;

  sort(begin(stuff), end(stuff));

  auto maximum = 0;
  auto missing = number_of_titles;
  for (auto x : stuff) {
    maximum = max(maximum, min(x, missing));
    --missing;
  }

  cout << maximum << endline;
}

auto main() -> int {
  ios::sync_with_stdio(false);

  auto tests = 10;
  cin >> tests;

  while (tests--) {
    solve();
  }

  return 0;
}