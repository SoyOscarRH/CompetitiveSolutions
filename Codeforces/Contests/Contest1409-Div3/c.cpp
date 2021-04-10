#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using num = int64_t;

constexpr auto endline = '\n';

auto solve(const num n, const num x, const num y) {
  auto step = 1;
  while (true) {
    auto current = y;
    for (auto i = 0; i < n and y >= 0; ++i) {
      if (current == x) return step;
      current -= step;
    }

    ++step;
  }

  return 1;
}

auto main() -> int {
  ios::sync_with_stdio(false);

  num tests;
  cin >> tests;

  while (tests--) {
    num a, b, x, y, n;
    cin >> n >> x >> y;
    auto step = solve(n, x, y);
    auto my_y = y, my_x = x;
    auto option1 = vector<num> {}, option2 = vector<num> {};
    for (auto i = 0; i < n; ++i, my_y -= step) { option1.push_back(my_y); }
    for (auto i = 0; i < n; ++i, my_x += step) { option2.push_back(my_x); }
    sort(begin(option1), end(option1));
    sort(begin(option2), end(option2));

    const auto& real = option1[0] < 0 ? option2 : option1;
    for (const auto ele : real) cout << ele << " ";
    cout << endline;
  }

  return 0;
}