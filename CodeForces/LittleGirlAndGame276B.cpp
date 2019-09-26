#include <algorithm>
#include <iostream>
#include <string>
#include <array>

using namespace std;

inline auto is_odd(int n) -> bool { return (n & 1) == 1; }

auto main() -> int {
  auto data = string {};
  cin >> data;

  array<int, 256> seen {};
  for (auto c : data) ++seen[c];

  auto num_odds = count_if(begin(seen), end(seen), is_odd);

  if (num_odds == 0 or num_odds == 1 or is_odd(num_odds))
    cout << "First" << endl;
  else
    cout << "Second" << endl;

  return 0;
}