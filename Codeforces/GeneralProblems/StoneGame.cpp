// https://codeforces.com/group/58ywWkEEOm/contest/247508/problem/C  [Summer Training Camp 2019,
// ESCOM IPN, AdHoc]

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

inline auto is_even(const int x) -> bool { return x & 1 == 0; }
inline auto is_odd(const int x) -> bool { return x & 1 == 1; }

inline auto doesPlayerOneWin(const int num_balls) -> bool {
  if (is_odd(num_balls)) return false;
  return not doesPlayerOneWin(num_balls / 2);
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int num_tests, num_balls;
  cin >> num_tests;

  for (auto test = 0; test < num_tests; ++test) {
    cin >> num_balls;
    cout << (doesPlayerOneWin(num_balls) ? "TAK" : "NIE") << "\n";
  }

  return 0;
}
