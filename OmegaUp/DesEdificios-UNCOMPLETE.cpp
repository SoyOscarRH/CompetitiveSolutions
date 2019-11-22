#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr auto endline = '\n';

template <typename T>
inline auto read() -> T {
  auto to_read = T {};
  cin >> to_read;
  return to_read;
}

auto solve() -> void {
  const auto number_of_titles = read<int>();
  cin >> number_of_titles;
  auto max_sol = solution(read<int>());
  auto curr_sol = max_sol;
  --number_of_titles;

  auto current = 0;
  while (number_of_titles--) {
    cin >> current;
    if (current >= curr_sol.height) { // add to the current
      auto times = maximum / maximumH;
      maximumH = min(current, maximumH);
      maximum = maximumH * times + 1;


    } else {
      maximumH = ;
      maximum = maximumH * times + 1;
    }
  }

  cout << maximum << endline;
}

auto main() -> int {
  ios::sync_with_stdio(false);

  solve();

  return 0;
}