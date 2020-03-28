#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
using num = long double;

constexpr auto endline = '\n';

const num pi = std::atan(1) * 4;

auto solve() -> void {
  num num_sides, length, expansion_distance, iterations;
  cin >> num_sides >> length >> expansion_distance >> iterations;

  const auto area = length * length * num_sides / (4 * tan(pi / num_sides));
  const auto linear_distance = expansion_distance * iterations;
  const auto rectangle = num_sides * (length * linear_distance);
  const auto circle = pi * linear_distance * linear_distance;

  cout << area + rectangle + circle << endline;
}

auto main() -> int {
  ios::sync_with_stdio(false);

  auto tests = 10;
  cin >> tests;

  std::cout << std::setprecision(18);
  while (tests--) {
    solve();
  }

  return 0;
}